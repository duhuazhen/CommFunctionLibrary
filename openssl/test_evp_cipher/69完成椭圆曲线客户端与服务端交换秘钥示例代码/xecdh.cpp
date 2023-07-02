/*/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               ������������ �Ĳܿ����˴��������Ϊѧϰ�ο�                **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       :c++ʵս��������������ѧ-����openssl
** Contact       : xiacaojun@qq.com
**  ����   : http://blog.csdn.net/jiedichina
**	��Ƶ�γ� : �����ƿ���	http://study.163.com/u/xiacaojun		
			   ��Ѷ����		https://jiedi.ke.qq.com/				
			   csdnѧԺ               http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
**             51ctoѧԺ              http://edu.51cto.com/lecturer/index/user_id-12016059.html	
** 			   ���Ŀ���		http://www.laoxiaketang.com 
**                 
**  c++ʵս��������������ѧ-����openssl   �γ�Ⱥ ��1064420127����Ⱥ���ش����ѧԱ����
**                           ΢�Ź��ں�  : jiedi2007
**		ͷ����	 : �Ĳܿ�
**
*****************************************************************************
//������������������c++ʵս��������������ѧ-����openssl �γ�  QQȺ��1064420127���ش����ѧԱ����*/

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
    //�õ���ǰ��Բ���߲���
    auto key = EVP_PKEY_get0_EC_KEY(pkey);
    //��ȡ��Բ����
    auto group = EC_KEY_get0_group(key);

    //pub_key ot EC_POINT
    EC_POINT* p = EC_POINT_new(group); //peer��Կ
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
        EC_KEY_get0_group(key),//��Բ����
        pub,                    //��Կ�� kG
        POINT_CONVERSION_HYBRID,   //���ݴ�Ÿ�ʽ
        pub_key,            //����ռ�
        1024,               //����ռ��ֽ���
        0                   //����������ģ���ѡ
    );
    return re;
}

///////////////////////////////////////
/// ������Բ���� ��Կ��
bool XECDH::CreateKey()
{
    //������Բ���߲�����������
    auto pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
    int re = EVP_PKEY_paramgen_init(pctx);
    if (re != 1)
    {
        EVP_PKEY_CTX_free(pctx);
        ERR_print_errors_fp(stderr);
        return false;
    }
    //ѡ����Բ����
    re = EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, nid);
    if (re != 1)
    {
        EVP_PKEY_CTX_free(pctx);
        ERR_print_errors_fp(stderr);
        return false;
    }

    //����ec�����洢��params
    EVP_PKEY* params = nullptr;
    re = EVP_PKEY_paramgen(pctx, &params);
    if (re != 1)
    {
        EVP_PKEY_CTX_free(pctx);
        ERR_print_errors_fp(stderr);
        return false;
    }
    EVP_PKEY_CTX_free(pctx);

    //������Բ������Կ��
    //����ec����������Կ�Դ���������
    auto kctx = EVP_PKEY_CTX_new(params,NULL);
    if (!kctx)
    {
        ERR_print_errors_fp(stderr);
        return false;
    }
    //��Կ�������ĳ�ʼ��
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
    //��Կ����������
    auto ctx = EVP_PKEY_CTX_new(pkey, NULL);
    if (!ctx)
    {
        ERR_print_errors_fp(stderr);
        return 0;
    }
    //��ʼ����Կ���� ECDH
    int re = EVP_PKEY_derive_init(ctx);
    if (re != 1)
    {
        EVP_PKEY_CTX_free(ctx);
        ERR_print_errors_fp(stderr);
        return 0;
    }
    //�趨�Է���Կ ��Կ��bG  ˽Կ��a    ������Կ��abG
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

    //���㹲����ԿabG
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