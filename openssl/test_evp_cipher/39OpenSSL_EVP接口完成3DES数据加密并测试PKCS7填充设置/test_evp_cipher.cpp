
#include <iostream>
#include <openssl/evp.h>
#include <openssl/err.h>


// _CRT_SECURE_NO_WARNINGS
//include <openssl/applink.c>
using namespace std;
int main(int argc, char* argv[])
{
    const unsigned char data[] = "1234567812345678";//����
    int data_size = strlen((char*)data);
    cout << "data_size = " << data_size << endl;
    unsigned char out[1024] = { 0 };                //���
    unsigned char key[128] = "12345678901234567890";//��Կ
    unsigned char iv[128] = { 0 };                  //��ʼ������
    //����DES 3DES �㷨
    auto cipher = EVP_des_ede3_cbc();
    //error:digital envelope routines:EVP_CipherInit_ex:initialization error
    //auto cipher = EVP_des_cbc();

    //��ȡ�㷨�ķ����С����
    int block_size = EVP_CIPHER_block_size(cipher);
    int key_size = EVP_CIPHER_key_length(cipher);
    int iv_size = EVP_CIPHER_iv_length(cipher);
    cout << "block_size = " << block_size << endl;
    cout << "key_size = " << key_size << endl;
    cout << "iv_size = " << iv_size << endl;

    //�ӽ���������
    auto ctx = EVP_CIPHER_CTX_new();
    //�����㷨��ʼ��
    int re = EVP_CipherInit(ctx, cipher, key, iv,
        1  //1 ��ʾ����
    );
    if (!re)
    {
        ERR_print_errors_fp(stderr);
        getchar();
        return -1;
    }
    cout << "EVP_CipherInit success��" << endl;

    //Ĭ�� PKCS7 �����С EVP_PADDING_PKCS7
    //�ر��Զ����
    //EVP_CIPHER_CTX_set_padding(ctx, 0);
    EVP_CIPHER_CTX_set_padding(ctx, EVP_PADDING_PKCS7);
    int out_size = 0;

    //ֻ��������С�õ�����,���ȡ���Զ���䣬�������ݶ���
    // ����Զ���䣬����EVP_CipherFinal �л�ȡ����
    EVP_CipherUpdate(ctx,
        out,           //���
        &out_size,     //������ݴ�С
        data,          //��������
        data_size
    );
    cout << "EVP_CipherUpdate size:" << out_size << endl;
    //ȡ�����һ�����ݣ���Ҫ���ģ���������padding���������
    int padding_size = 0;
    EVP_CipherFinal(ctx, out + out_size, &padding_size);
    cout << "padding_size = " << padding_size << endl;
    out_size += padding_size;
    cout << out_size << ":" << out << endl;
    //�ͷ�������
    EVP_CIPHER_CTX_free(ctx);

    getchar();
    return 0;
}