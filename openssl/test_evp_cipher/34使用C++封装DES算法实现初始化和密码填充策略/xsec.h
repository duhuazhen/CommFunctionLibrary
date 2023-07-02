#pragma once
#include <string>
#include <openssl/des.h>
enum XSecType
{
    XDES_ECB,
    XDES_CBC
};
/*
XSec sec;
sec.Init(XDES_ECB,"12345678",true);

*/
class XSec
{
public:
    /////////////////////////////////////////////////////////////////
    ///��ʼ�����ܶ�������֮ǰ������
    ///@para type ��������
    ///@para pass ��Կ�������Ƕ�����
    ///@is_en true���� false����
    ///@return �Ƿ�ɹ�
    virtual bool Init(XSecType type, const std::string& pass, bool is_en);

    /////////////////////////////////////////////////////////////////////
    /// �ӽ�������
    ///@para in ��������
    ///@para in_size ���ݴ�С
    ///@para �������
    ///@para �ɹ����ؼӽ��ܺ������ֽڴ�С��ʧ�ܷ���0
    virtual int Encrypt(const unsigned char* in, int in_size, unsigned char* out);

private:
    ////////////////////////////////////////////////////////////////////////
    /// DES ECBģʽ����
    int EnDesECB(const unsigned char* in, int in_size, unsigned char* out);

    //DES�㷨��Կ
    DES_key_schedule ks_;

    //�����㷨����
    XSecType type_;

    bool is_en_;

    //���ݿ��С �����С
    int block_size_ = 0;
};

