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

#pragma once
typedef struct evp_pkey_st EVP_PKEY;
class XECDH
{
public:
    XECDH();
    ///////////////////////////////////////
    /// ������Բ���� ��Կ��
    bool CreateKey();

    int GetPubKey(unsigned unsigned char* pub_key);

    EVP_PKEY* OctToPKey(const unsigned char* pub_key, int size);

    int Compute(unsigned char* out, const unsigned char* peer_key, int key_size);
         
private:
    //ѡ����Բ����
    int nid = 0;

    //��Կ��
    EVP_PKEY* pkey = 0;
};

