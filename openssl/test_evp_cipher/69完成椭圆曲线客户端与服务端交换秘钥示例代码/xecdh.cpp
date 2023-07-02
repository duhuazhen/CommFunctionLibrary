/*/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               创建：丁宋涛 夏曹俊，此代码可用作为学习参考                **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       :c++实战区块链核心密码学-基于openssl
** Contact       : xiacaojun@qq.com
**  博客   : http://blog.csdn.net/jiedichina
**	视频课程 : 网易云课堂	http://study.163.com/u/xiacaojun		
			   腾讯课堂		https://jiedi.ke.qq.com/				
			   csdn学院               http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
**             51cto学院              http://edu.51cto.com/lecturer/index/user_id-12016059.html	
** 			   老夏课堂		http://www.laoxiaketang.com 
**                 
**  c++实战区块链核心密码学-基于openssl   课程群 ：1064420127加入群下载代码和学员交流
**                           微信公众号  : jiedi2007
**		头条号	 : 夏曹俊
**
*****************************************************************************
//！！！！！！！！！c++实战区块链核心密码学-基于openssl 课程  QQ群：1064420127下载代码和学员交流*/

#include "xecdh.h"
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/ec.h>
#ifdef _WIN32
#include <openssl/applink.c>
#endif
#include<iostream>
using namespace std;

XECDH::XECDH()
{
    //NID_sm2
    nid = NID_secp256k1;
}
EVP_PKEY* XECDH::OctToPKey(const unsigned char* pub_key, int size)
{
    //拿到当前椭圆曲线参数
    auto key = EVP_PKEY_get0_EC_KEY(pkey);
    //获取椭圆曲线
    auto group = EC_KEY_get0_group(key);

    //pub_key ot EC_POINT
    EC_POINT* p = EC_POINT_new(group); //peer公钥
    EC_POINT_oct2point(group, p, pub_key, size, NULL);
    auto ec = EC_KEY_new();
    EC_KEY_set_group(ec, group);
    EC_KEY_set_public_key(ec, p);
    EC_POINT_free(p);
    auto peerkey = EVP_PKEY_new();
    EVP_PKEY_set1_EC_KEY(peerkey, ec);
    EC_KEY_free(ec);
    return peerkey;
}

int XECDH::GetPubKey(unsigned char* pub_key)
{
    if (!pkey)return 0;
    auto key = EVP_PKEY_get0_EC_KEY(pkey);
    auto pub = EC_KEY_get0_public_key(key);
    int re = EC_POINT_point2oct(
        EC_KEY_get0_group(key),//椭圆曲线
        pub,                    //公钥点 kG
        POINT_CONVERSION_HYBRID,   //数据存放格式
        pub_key,            //输出空间
        1024,               //输出空间字节数
        0                   //处理的上下文，可选
    );
    return re;
}

///////////////////////////////////////
/// 生成椭圆曲线 秘钥对
bool XECDH::CreateKey()
{
    //生成椭圆曲线参数的上下文
    auto pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
    int re = EVP_PKEY_paramgen_init(pctx);
    if (re != 1)
    {
        EVP_PKEY_CTX_free(pctx);
        ERR_print_errors_fp(stderr);
        return false;
    }
    //选择椭圆曲线
    re = EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, nid);
    if (re != 1)
    {
        EVP_PKEY_CTX_free(pctx);
        ERR_print_errors_fp(stderr);
        return false;
    }

    //生成ec参数存储到params
    EVP_PKEY* params = nullptr;
    re = EVP_PKEY_paramgen(pctx, &params);
    if (re != 1)
    {
        EVP_PKEY_CTX_free(pctx);
        ERR_print_errors_fp(stderr);
        return false;
    }
    EVP_PKEY_CTX_free(pctx);

    //生成椭圆曲线秘钥对
    //根据ec参数生成秘钥对创建上下文
    auto kctx = EVP_PKEY_CTX_new(params,NULL);
    if (!kctx)
    {
        ERR_print_errors_fp(stderr);
        return false;
    }
    //秘钥对上下文初始化
    re = EVP_PKEY_keygen_init(kctx);
    if (re != 1)
    {
        EVP_PKEY_CTX_free(kctx);
        ERR_print_errors_fp(stderr);
        return false;
    }
    re = EVP_PKEY_keygen(kctx, &pkey);
    EVP_PKEY_CTX_free(kctx);
    if (re != 1)
    {
        ERR_print_errors_fp(stderr);
        return false;
    }
    cout << "EVP_PKEY_keygen success!" << endl;
    return true;
}

int XECDH::Compute(unsigned char* out, const unsigned char* peer_key, int key_size)
{
    //秘钥交换上下文
    auto ctx = EVP_PKEY_CTX_new(pkey, NULL);
    if (!ctx)
    {
        ERR_print_errors_fp(stderr);
        return 0;
    }
    //初始化秘钥交换 ECDH
    int re = EVP_PKEY_derive_init(ctx);
    if (re != 1)
    {
        EVP_PKEY_CTX_free(ctx);
        ERR_print_errors_fp(stderr);
        return 0;
    }
    //设定对方公钥 公钥：bG  私钥：a    共享秘钥：abG
    auto peerkey = OctToPKey(peer_key, key_size);
    re = EVP_PKEY_derive_set_peer(ctx, peerkey);
    if (re != 1)
    {
        EVP_PKEY_free(peerkey);
        EVP_PKEY_CTX_free(ctx);
        ERR_print_errors_fp(stderr);
        return 0;
    }
    EVP_PKEY_free(peerkey);

    //计算共享秘钥abG
    size_t re_size = 1024;
    re = EVP_PKEY_derive(ctx, out, &re_size);
    if (re != 1)
    {
        EVP_PKEY_free(peerkey);
        EVP_PKEY_CTX_free(ctx);
        ERR_print_errors_fp(stderr);
        return 0;
    }
    EVP_PKEY_CTX_free(ctx);
    return re_size;
}