/*/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               创建：丁宋涛 夏曹俊，此代码可用作为学习参考                **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       :c++实战区块链核心密码学-基于openssl
** Contact       : xiacaojun@qq.com
**  博客   : http://blog.csdn.net/jiedichina
**	视频课程 : 网易云课堂	http://study.163.com/u/xiacaojun		
			   腾讯课堂		https://jiedi.ke.qq.com/				
			   csdn学院               http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
**             51cto学院              http://edu.51cto.com/lecturer/index/user_id-12016059.html	
** 			   老夏课堂		http://www.laoxiaketang.com 
**                 
**  c++实战区块链核心密码学-基于openssl   课程群 ：1064420127加入群下载代码和学员交流
**                           微信公众号  : jiedi2007
**		头条号	 : 夏曹俊
**
*****************************************************************************
//！！！！！！！！！c++实战区块链核心密码学-基于openssl 课程  QQ群：1064420127下载代码和学员交流*/

#include <iostream>
#include "xecdh.h"
using namespace std;

int main(int argc, char* argv[])
{
    cout << "Test ECDH" << endl;
    //服务端公钥
    unsigned char spub[1024] = { 0 };
    
    //客户端公钥
    unsigned char cpub[1024] = { 0 };

    
    XECDH server;
    XECDH client;
    //服务端和客户端都生成秘钥对
    cout << server.CreateKey() << endl;
    int spub_size = server.GetPubKey(spub);
    cout << "server pubkey:" << spub_size << ":" << spub << endl;

    cout << client.CreateKey() << endl;
    int cpub_size = client.GetPubKey(cpub);
    cout << "client pubkey:" << cpub_size << ":" << cpub << endl;

    unsigned char ssec[1024] = { 0 };
    unsigned char csec[1024] = { 0 };
    cout << "server:" << server.Compute(ssec, cpub, cpub_size) <<":"<<ssec<< endl;
    cout << "client:" << client.Compute(csec, spub, spub_size) << ":" << csec << endl;

    getchar();
    return 0;
}










































