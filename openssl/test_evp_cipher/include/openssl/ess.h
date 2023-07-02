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

/*
 * Copyright 2019-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_ESS_H
# define OPENSSL_ESS_H

# include <openssl/opensslconf.h>

# ifdef  __cplusplus
extern "C" {
# endif
# include <openssl/safestack.h>
# include <openssl/x509.h>
# include <openssl/esserr.h>


typedef struct ESS_issuer_serial ESS_ISSUER_SERIAL;
typedef struct ESS_cert_id ESS_CERT_ID;
typedef struct ESS_signing_cert ESS_SIGNING_CERT;

DEFINE_OR_DECLARE_STACK_OF(ESS_CERT_ID)

typedef struct ESS_signing_cert_v2_st ESS_SIGNING_CERT_V2;
typedef struct ESS_cert_id_v2_st ESS_CERT_ID_V2;

DEFINE_OR_DECLARE_STACK_OF(ESS_CERT_ID_V2)

DECLARE_ASN1_ALLOC_FUNCTIONS(ESS_ISSUER_SERIAL)
DECLARE_ASN1_ENCODE_FUNCTIONS_only(ESS_ISSUER_SERIAL, ESS_ISSUER_SERIAL)
DECLARE_ASN1_DUP_FUNCTION(ESS_ISSUER_SERIAL)

DECLARE_ASN1_ALLOC_FUNCTIONS(ESS_CERT_ID)
DECLARE_ASN1_ENCODE_FUNCTIONS_only(ESS_CERT_ID, ESS_CERT_ID)
DECLARE_ASN1_DUP_FUNCTION(ESS_CERT_ID)

DECLARE_ASN1_ALLOC_FUNCTIONS(ESS_SIGNING_CERT)
DECLARE_ASN1_ENCODE_FUNCTIONS_only(ESS_SIGNING_CERT, ESS_SIGNING_CERT)
DECLARE_ASN1_DUP_FUNCTION(ESS_SIGNING_CERT)

DECLARE_ASN1_ALLOC_FUNCTIONS(ESS_CERT_ID_V2)
DECLARE_ASN1_ENCODE_FUNCTIONS_only(ESS_CERT_ID_V2, ESS_CERT_ID_V2)
DECLARE_ASN1_DUP_FUNCTION(ESS_CERT_ID_V2)

DECLARE_ASN1_ALLOC_FUNCTIONS(ESS_SIGNING_CERT_V2)
DECLARE_ASN1_ENCODE_FUNCTIONS_only(ESS_SIGNING_CERT_V2, ESS_SIGNING_CERT_V2)
DECLARE_ASN1_DUP_FUNCTION(ESS_SIGNING_CERT_V2)

# ifdef  __cplusplus
}
# endif
#endif
