
#include <iostream>
#include <openssl/des.h>
using namespace std;


int main(int argc, char* argv[])
{

    unsigned char data[] = "1234567";
    unsigned char out[1024] = { 0 };
    unsigned char out2[1024] = { 0 };
    const_DES_cblock key = "1234567";
    DES_key_schedule key_sch;
    
    //1设置秘钥
    DES_set_key(&key, &key_sch);
    
    //数据加密 8字节
    DES_ecb_encrypt((const_DES_cblock*)data, (DES_cblock*)out, &key_sch, DES_ENCRYPT);
    cout << out << endl;
    
    //数据解密
    DES_ecb_encrypt((const_DES_cblock*)out, (DES_cblock*)out2, &key_sch, DES_DECRYPT);
    cout << out2 << endl;

    getchar();
    return 0;
}