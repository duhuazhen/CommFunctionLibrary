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
 * Copyright 1995-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_CAST_H
# define OPENSSL_CAST_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_CAST_H
# endif

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_CAST
# ifdef  __cplusplus
extern "C" {
# endif

# define CAST_BLOCK      8
# define CAST_KEY_LENGTH 16

# ifndef OPENSSL_NO_DEPRECATED_3_0

#  define CAST_ENCRYPT    1
#  define CAST_DECRYPT    0

#  define CAST_LONG unsigned int

typedef struct cast_key_st {
    CAST_LONG data[32];
    int short_key;              /* Use reduced rounds for short key */
} CAST_KEY;

# endif /* OPENSSL_NO_DEPRECATED_3_0 */

DEPRECATEDIN_3_0(void CAST_set_key(CAST_KEY *key, int len,
                                   const unsigned char *data))
DEPRECATEDIN_3_0(void CAST_ecb_encrypt(const unsigned char *in,
                                       unsigned char *out,
                                       const CAST_KEY *key,
                                       int enc))
DEPRECATEDIN_3_0(void CAST_encrypt(CAST_LONG *data,
                                   const CAST_KEY *key))
DEPRECATEDIN_3_0(void CAST_decrypt(CAST_LONG *data,
                                   const CAST_KEY *key))
DEPRECATEDIN_3_0(void CAST_cbc_encrypt(const unsigned char *in,
                                       unsigned char *out,
                                       long length,
                                       const CAST_KEY *ks,
                                       unsigned char *iv,
                                       int enc))
DEPRECATEDIN_3_0(void CAST_cfb64_encrypt(const unsigned char *in,
                                         unsigned char *out,
                                         long length,
                                         const CAST_KEY *schedule,
                                         unsigned char *ivec,
                                         int *num,
                                         int enc))
DEPRECATEDIN_3_0(void CAST_ofb64_encrypt(const unsigned char *in,
                                         unsigned char *out,
                                         long length,
                                         const CAST_KEY *schedule,
                                         unsigned char *ivec,
                                         int *num))

# ifdef  __cplusplus
}
# endif
# endif

#endif