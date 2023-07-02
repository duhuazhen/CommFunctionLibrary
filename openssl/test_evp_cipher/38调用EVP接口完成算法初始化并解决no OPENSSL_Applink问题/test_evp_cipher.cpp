
#include <iostream>
#include <openssl/evp.h>
#include <openssl/err.h>


// _CRT_SECURE_NO_WARNINGS
//#include <openssl/applink.c>
using namespace std;
int main(int argc, char* argv[])
{
    const unsigned char data[] = "1234567812345678";//输入
    unsigned char out[1024] = { 0 };                //输出
    unsigned char key[128] = "12345678901234567890";//秘钥
    unsigned char iv[128] = { 0 };                  //初始化向量
    //三重DES 3DES 算法
    auto cipher = EVP_des_ede3_cbc();
    //error:digital envelope routines:EVP_CipherInit_ex:initialization error
    //auto cipher = EVP_des_cbc();

    //获取算法的分组大小（）
    int block_size = EVP_CIPHER_block_size(cipher);
    int key_size = EVP_CIPHER_key_length(cipher);
    int iv_size = EVP_CIPHER_iv_length(cipher);
    cout << "block_size = " << block_size << endl;
    cout << "key_size = " << key_size << endl;
    cout << "iv_size = " << iv_size << endl;

    //加解密上下文
    auto ctx = EVP_CIPHER_CTX_new();
    //加密算法初始化
    int re = EVP_CipherInit(ctx, cipher, key, iv,
        1  //1 表示加密
    );
    if (!re)
    {
        ERR_print_errors_fp(stderr);
        getchar();
        return -1;
    }
    cout << "EVP_CipherInit success！" << endl;
    

    //释放上下文
    EVP_CIPHER_CTX_free(ctx);

    getchar();
    return 0;
}