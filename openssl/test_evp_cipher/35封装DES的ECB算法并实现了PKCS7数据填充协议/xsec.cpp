
#include "xsec.h"
/////////////////////////////////////////////////////////////////
///��ʼ�����ܶ�������֮ǰ������
///@para type ��������
///@para pass ��Կ�������Ƕ�����
///@is_en true���� false����
///@return �Ƿ�ɹ�
bool XSec::Init(XSecType type, const std::string& pass, bool is_en)
{
    this->type_ = type;
    this->is_en_ = is_en;
    block_size_ = DES_KEY_SZ;
    ///������ԣ�����8�ֽڵĶ������ٵĲ���0
    const_DES_cblock key = { 0 }; //�ٵĲ���0
    int key_size = pass.size();
    //����8�ֽڵĶ�����
    if (key_size > block_size_) key_size = block_size_;
    //�ٵĲ���0
    memcpy(&key, pass.data(), key_size);

    DES_set_key(&key, &ks_);
    return true;
}


/////////////////////////////////////////////////////////////////////
/// �ӽ�������
///@para in ��������
///@para in_size ���ݴ�С
///@para �������
///@para �ɹ����ؼӽ��ܺ������ֽڴ�С��ʧ�ܷ���0
int XSec::Encrypt(const unsigned char* in, int in_size, unsigned char* out)
{
    if (type_ == XDES_ECB)
    {
        if (is_en_)
        {
            return EnDesECB(in,in_size,out);
        }
    }
}

////////////////////////////////////////////////////////////////////////
/// DES ECBģʽ����
int XSec::EnDesECB(const unsigned char* in, int in_size, unsigned char* out)
{
    ///������� PKCS7 Padding
    /*
    �������ݳ�����Ҫ���n(n>0)���ֽڲŶ��룬��ô���n���ֽڣ�ÿ���ֽڶ���n;
    ������ݱ�����Ѿ������ˣ������һ�鳤��Ϊ���С�����ݣ�ÿ���ֽڶ��ǿ��С��
    */
    unsigned char pad[8] = { 0 };
    int padding_size = block_size_ - (in_size % block_size_);
    //���벹����ֽڴ�С
    memset(pad, padding_size, sizeof(pad));
    int i = 0;
    for ( ;i < in_size; i += block_size_)
    {
        //���һ�����ݣ�С��block_size_ ��Ҫ���
        if (in_size - i < block_size_)
        {
            //��������
            memcpy(pad, in + i, in_size - i);
            break;
        }
        DES_ecb_encrypt((const_DES_cblock*)(in + i),
            (DES_cblock*)(out + i),
            &ks_,
            DES_ENCRYPT
        );
    }
    //���� PKCS7��β
    DES_ecb_encrypt((const_DES_cblock*)pad,
        (DES_cblock*)(out + i),
        &ks_,
        DES_ENCRYPT
    );
    return in_size + padding_size;
}