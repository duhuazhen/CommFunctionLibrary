
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


/////////////////////////////////////////////////////////////////////
/// 加解密数据
///@para in 输入数据
///@para in_size 数据大小
///@para 输出数据
///@para 成功返回加解密后数据字节大小，失败返回0
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
/// DES ECB模式加密
int XSec::EnDesECB(const unsigned char* in, int in_size, unsigned char* out)
{
    ///数据填充 PKCS7 Padding
    /*
    假设数据长度需要填充n(n>0)个字节才对齐，那么填充n个字节，每个字节都是n;
    如果数据本身就已经对齐了，则填充一块长度为块大小的数据，每个字节都是块大小。
    */
    unsigned char pad[8] = { 0 };
    int padding_size = block_size_ - (in_size % block_size_);
    //填入补充的字节大小
    memset(pad, padding_size, sizeof(pad));
    int i = 0;
    for ( ;i < in_size; i += block_size_)
    {
        //最后一块数据，小于block_size_ 需要填充
        if (in_size - i < block_size_)
        {
            //填入数据
            memcpy(pad, in + i, in_size - i);
            break;
        }
        DES_ecb_encrypt((const_DES_cblock*)(in + i),
            (DES_cblock*)(out + i),
            &ks_,
            DES_ENCRYPT
        );
    }
    //补充 PKCS7结尾
    DES_ecb_encrypt((const_DES_cblock*)pad,
        (DES_cblock*)(out + i),
        &ks_,
        DES_ENCRYPT
    );
    return in_size + padding_size;
}