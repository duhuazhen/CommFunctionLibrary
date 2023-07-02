
#include <iostream>
#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#ifdef _WIN32
#include <openssl/applink.c>
#endif
using namespace std;
void PrintBn(const BIGNUM* n)
{
    //大数对象转为二进制
    unsigned char to[256] = { 0 };
    BN_bn2bin(n, to);
    int byte_size = BN_num_bytes(n);
    for (int i = 0; i < byte_size; i++)
        printf("%02x", to[i]);
    printf("\n");
}
//////////////////////////////////////////////////////
/// 生成RSA 秘钥对
/// @return 返回的pkey由调用EVP_PKEY_free释放
EVP_PKEY* EvpRsaKey()
{
    //1 创建RSA公钥加密上下文
    auto ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
    if (!ctx)
    {
        ERR_print_errors_fp(stderr);
        return NULL;
    }

    //2 初始化密钥对生成上下文
    if (EVP_PKEY_keygen_init(ctx) <= 0)
    {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        return NULL;
    }

    //3 设置参数 RSA 秘钥位数
    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 1024) <= 0)
    {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        return NULL;
    }

    //4 秘钥生成
    EVP_PKEY* pkey = NULL;
    //内部会生成EVP_PKEY 空间
    if (EVP_PKEY_keygen(ctx, &pkey) <= 0)
    {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        return NULL;
    }
    //释放上下文
    EVP_PKEY_CTX_free(ctx);

    //获取参数列表
    auto tp = EVP_PKEY_gettable_params(pkey);
    while (tp)
    {
        if (!tp->key)break;
        cout << tp->key << endl;
        tp++;
    }
    //获取参数的值
    BIGNUM* d = 0;
    EVP_PKEY_get_bn_param(pkey, "d", &d);
    PrintBn(d);
    BN_free(d);

    //输出公钥pem文件
    FILE* pubf = fopen("pubkey.pem", "w");
    PEM_write_RSAPublicKey(pubf, EVP_PKEY_get0_RSA(pkey));


    //输出明文私钥pem文件
    FILE* prif = fopen("prikey.pem", "w");
    PEM_write_RSAPrivateKey(prif, EVP_PKEY_get0_RSA(pkey),
        NULL,   //加密的上下文
        NULL,   //秘钥
        0,      //秘钥长度
        NULL,   //加密回调函数
        NULL    //用户数据回调使用
    );
    fclose(pubf);
    fclose(prif);
    return pkey;
}
int main(int argc, char* argv[])
{
    unsigned char data[1024] = { 0 };
    unsigned char out[2046] = { 0 };
    unsigned char out2[2046] = { 0 };
    //初始化测试数据
    for (int i = 0; i < sizeof(data) - 1; i++)
    {
        data[i] = 'A' + i % 26;
    }
    int data_size = sizeof(data);

    auto pkey = EvpRsaKey();



    EVP_PKEY_free(pkey);


    getchar();
    return 0;
}










































