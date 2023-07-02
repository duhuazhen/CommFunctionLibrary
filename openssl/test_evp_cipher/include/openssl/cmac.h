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
 * Copyright 2010-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_CMAC_H
# define OPENSSL_CMAC_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_CMAC_H
# endif

# ifndef OPENSSL_NO_CMAC

#  ifdef __cplusplus
extern "C" {
#  endif

#  include <openssl/evp.h>

#  ifndef OPENSSL_NO_DEPRECATED_3_0
/* Opaque */
typedef struct CMAC_CTX_st CMAC_CTX;
#  endif

DEPRECATEDIN_3_0(CMAC_CTX *CMAC_CTX_new(void))
DEPRECATEDIN_3_0(void CMAC_CTX_cleanup(CMAC_CTX *ctx))
DEPRECATEDIN_3_0(void CMAC_CTX_free(CMAC_CTX *ctx))
DEPRECATEDIN_3_0(EVP_CIPHER_CTX *CMAC_CTX_get0_cipher_ctx(CMAC_CTX *ctx))
DEPRECATEDIN_3_0(int CMAC_CTX_copy(CMAC_CTX *out, const CMAC_CTX *in))

DEPRECATEDIN_3_0(int CMAC_Init(CMAC_CTX *ctx, const void *key, size_t keylen,
              const EVP_CIPHER *cipher, ENGINE *impl))
DEPRECATEDIN_3_0(int CMAC_Update(CMAC_CTX *ctx, const void *data, size_t dlen))
DEPRECATEDIN_3_0(int CMAC_Final(CMAC_CTX *ctx, unsigned char *out,
                                size_t *poutlen))
DEPRECATEDIN_3_0(int CMAC_resume(CMAC_CTX *ctx))

#  ifdef  __cplusplus
}
#  endif

# endif
#endif
