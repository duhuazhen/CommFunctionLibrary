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