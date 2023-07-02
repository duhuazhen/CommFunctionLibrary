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

#pragma once
typedef struct evp_pkey_st EVP_PKEY;
class XECDH
{
public:
    XECDH();
    ///////////////////////////////////////
    /// 生成椭圆曲线 秘钥对
    bool CreateKey();

    int GetPubKey(unsigned unsigned char* pub_key);

    EVP_PKEY* OctToPKey(const unsigned char* pub_key, int size);

    int Compute(unsigned char* out, const unsigned char* peer_key, int key_size);
         
private:
    //选择椭圆曲线
    int nid = 0;

    //秘钥对
    EVP_PKEY* pkey = 0;
};

