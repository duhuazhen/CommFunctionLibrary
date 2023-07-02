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
 * Copyright (c) 2019, Oracle and/or its affiliates.  All rights reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <openssl/params.h>
#include <openssl/types.h>

OSSL_PARAM_BLD *OSSL_PARAM_BLD_new(void);
OSSL_PARAM *OSSL_PARAM_BLD_to_param(OSSL_PARAM_BLD *bld);
void OSSL_PARAM_BLD_free(OSSL_PARAM_BLD *bld);
void OSSL_PARAM_BLD_free_params(OSSL_PARAM *params);

int OSSL_PARAM_BLD_push_int(OSSL_PARAM_BLD *bld, const char *key, int val);
int OSSL_PARAM_BLD_push_uint(OSSL_PARAM_BLD *bld, const char *key,
                             unsigned int val);
int OSSL_PARAM_BLD_push_long(OSSL_PARAM_BLD *bld, const char *key,
                             long int val);
int OSSL_PARAM_BLD_push_ulong(OSSL_PARAM_BLD *bld, const char *key,
                              unsigned long int val);
int OSSL_PARAM_BLD_push_int32(OSSL_PARAM_BLD *bld, const char *key,
                              int32_t val);
int OSSL_PARAM_BLD_push_uint32(OSSL_PARAM_BLD *bld, const char *key,
                               uint32_t val);
int OSSL_PARAM_BLD_push_int64(OSSL_PARAM_BLD *bld, const char *key,
                              int64_t val);
int OSSL_PARAM_BLD_push_uint64(OSSL_PARAM_BLD *bld, const char *key,
                               uint64_t val);
int OSSL_PARAM_BLD_push_size_t(OSSL_PARAM_BLD *bld, const char *key,
                               size_t val);
int OSSL_PARAM_BLD_push_double(OSSL_PARAM_BLD *bld, const char *key,
                               double val);
int OSSL_PARAM_BLD_push_BN(OSSL_PARAM_BLD *bld, const char *key,
                           const BIGNUM *bn);
int OSSL_PARAM_BLD_push_BN_pad(OSSL_PARAM_BLD *bld, const char *key,
                               const BIGNUM *bn, size_t sz);
int OSSL_PARAM_BLD_push_utf8_string(OSSL_PARAM_BLD *bld, const char *key,
                                    const char *buf, size_t bsize);
int OSSL_PARAM_BLD_push_utf8_ptr(OSSL_PARAM_BLD *bld, const char *key,
                                 char *buf, size_t bsize);
int OSSL_PARAM_BLD_push_octet_string(OSSL_PARAM_BLD *bld, const char *key,
                                     const void *buf, size_t bsize);
int OSSL_PARAM_BLD_push_octet_ptr(OSSL_PARAM_BLD *bld, const char *key,
                                  void *buf, size_t bsize);
