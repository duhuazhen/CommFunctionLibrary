#include "xsec.h"
/////////////////////////////////////////////////////////////////
///初始化加密对象，清理之前的数据
///@para type 加密类型
///@para pass 秘钥，可以是二进制
///@is_en true加密 false解密
///@return 是否成功
bool XSec::Init(XSecType type, const std::string& pass, bool is_en)
{
    this->type_ = type;
    this->is_en_ = is_en;
    block_size_ = DES_KEY_SZ;
    ///密码策略，超出8字节的丢弃，少的补充0
    const_DES_cblock key = { 0 }; //少的补充0
    int key_size = pass.size();
    //超出8字节的丢弃，
    if (key_size > block_size_) key_size = block_size_;
    //少的补充0
    memcpy(&key, pass.data(), key_size);

    DES_set_key(&key, &ks_);
    return true;
}