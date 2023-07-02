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
 * Copyright 2005-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_DTLS1_H
# define OPENSSL_DTLS1_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_DTLS1_H
# endif

#ifdef  __cplusplus
extern "C" {
#endif

#include <openssl/opensslconf.h>

# define DTLS1_VERSION                   0xFEFF
# define DTLS1_2_VERSION                 0xFEFD
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define DTLS_MIN_VERSION                DTLS1_VERSION
#  define DTLS_MAX_VERSION                DTLS1_2_VERSION
# endif
# define DTLS1_VERSION_MAJOR             0xFE

# define DTLS1_BAD_VER                   0x0100

/* Special value for method supporting multiple versions */
# define DTLS_ANY_VERSION                0x1FFFF

/* lengths of messages */
/*
 * Actually the max cookie length in DTLS is 255. But we can't change this now
 * due to compatibility concerns.
 */
# define DTLS1_COOKIE_LENGTH                     256

# define DTLS1_RT_HEADER_LENGTH                  13

# define DTLS1_HM_HEADER_LENGTH                  12

# define DTLS1_HM_BAD_FRAGMENT                   -2
# define DTLS1_HM_FRAGMENT_RETRY                 -3

# define DTLS1_CCS_HEADER_LENGTH                  1

# define DTLS1_AL_HEADER_LENGTH                   2

/* Timeout multipliers */
# define DTLS1_TMO_READ_COUNT                      2
# define DTLS1_TMO_WRITE_COUNT                     2

# define DTLS1_TMO_ALERT_COUNT                     12

#ifdef  __cplusplus
}
#endif
#endif
