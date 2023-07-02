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
 * Copyright 1995-2017 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_TXT_DB_H
# define OPENSSL_TXT_DB_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_TXT_DB_H
# endif

# include <openssl/opensslconf.h>
# include <openssl/bio.h>
# include <openssl/safestack.h>
# include <openssl/lhash.h>

# define DB_ERROR_OK                     0
# define DB_ERROR_MALLOC                 1
# define DB_ERROR_INDEX_CLASH            2
# define DB_ERROR_INDEX_OUT_OF_RANGE     3
# define DB_ERROR_NO_INDEX               4
# define DB_ERROR_INSERT_INDEX_CLASH     5
# define DB_ERROR_WRONG_NUM_FIELDS       6

#ifdef  __cplusplus
extern "C" {
#endif

typedef OPENSSL_STRING *OPENSSL_PSTRING;
DEFINE_SPECIAL_STACK_OF(OPENSSL_PSTRING, OPENSSL_STRING)

typedef struct txt_db_st {
    int num_fields;
    STACK_OF(OPENSSL_PSTRING) *data;
    LHASH_OF(OPENSSL_STRING) **index;
    int (**qual) (OPENSSL_STRING *);
    long error;
    long arg1;
    long arg2;
    OPENSSL_STRING *arg_row;
} TXT_DB;

TXT_DB *TXT_DB_read(BIO *in, int num);
long TXT_DB_write(BIO *out, TXT_DB *db);
int TXT_DB_create_index(TXT_DB *db, int field, int (*qual) (OPENSSL_STRING *),
                        OPENSSL_LH_HASHFUNC hash, OPENSSL_LH_COMPFUNC cmp);
void TXT_DB_free(TXT_DB *db);
OPENSSL_STRING *TXT_DB_get_by_index(TXT_DB *db, int idx,
                                    OPENSSL_STRING *value);
int TXT_DB_insert(TXT_DB *db, OPENSSL_STRING *value);

#ifdef  __cplusplus
}
#endif

#endif
