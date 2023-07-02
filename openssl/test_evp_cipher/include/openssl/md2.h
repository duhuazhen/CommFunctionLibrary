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

#ifndef OPENSSL_MD2_H
# define OPENSSL_MD2_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_MD2_H
# endif

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_MD2
#  include <stddef.h>
#  ifdef  __cplusplus
extern "C" {
#  endif

#  define MD2_DIGEST_LENGTH       16

#  if !defined(OPENSSL_NO_DEPRECATED_3_0)

typedef unsigned char MD2_INT;

#   define MD2_BLOCK               16

typedef struct MD2state_st {
    unsigned int num;
    unsigned char data[MD2_BLOCK];
    MD2_INT cksm[MD2_BLOCK];
    MD2_INT state[MD2_BLOCK];
} MD2_CTX;
#  endif

DEPRECATEDIN_3_0(const char *MD2_options(void))
DEPRECATEDIN_3_0(int MD2_Init(MD2_CTX *c))
DEPRECATEDIN_3_0(int MD2_Update(MD2_CTX *c, const unsigned char *data,
                                size_t len))
DEPRECATEDIN_3_0(int MD2_Final(unsigned char *md, MD2_CTX *c))
DEPRECATEDIN_3_0(unsigned char *MD2(const unsigned char *d, size_t n,
                 unsigned char *md))

#  ifdef  __cplusplus
}
#  endif
# endif
#endif
