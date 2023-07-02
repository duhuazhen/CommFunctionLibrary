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
 * Generated by util/mkerr.pl DO NOT EDIT
 * Copyright 1995-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_TSERR_H
# define OPENSSL_TSERR_H
# pragma once

# include <openssl/opensslconf.h>
# include <openssl/symhacks.h>


# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_TS

#  ifdef  __cplusplus
extern "C"
#  endif
int ERR_load_TS_strings(void);

/*
 * TS function codes.
 */
# ifndef OPENSSL_NO_DEPRECATED_3_0
#   define TS_F_DEF_SERIAL_CB                               0
#   define TS_F_DEF_TIME_CB                                 0
#   define TS_F_INT_TS_RESP_VERIFY_TOKEN                    0
#   define TS_F_PKCS7_TO_TS_TST_INFO                        0
#   define TS_F_TS_ACCURACY_SET_MICROS                      0
#   define TS_F_TS_ACCURACY_SET_MILLIS                      0
#   define TS_F_TS_ACCURACY_SET_SECONDS                     0
#   define TS_F_TS_CHECK_IMPRINTS                           0
#   define TS_F_TS_CHECK_NONCES                             0
#   define TS_F_TS_CHECK_POLICY                             0
#   define TS_F_TS_CHECK_SIGNING_CERTS                      0
#   define TS_F_TS_CHECK_STATUS_INFO                        0
#   define TS_F_TS_COMPUTE_IMPRINT                          0
#   define TS_F_TS_CONF_INVALID                             0
#   define TS_F_TS_CONF_LOAD_CERT                           0
#   define TS_F_TS_CONF_LOAD_CERTS                          0
#   define TS_F_TS_CONF_LOAD_KEY                            0
#   define TS_F_TS_CONF_LOOKUP_FAIL                         0
#   define TS_F_TS_CONF_SET_DEFAULT_ENGINE                  0
#   define TS_F_TS_GET_STATUS_TEXT                          0
#   define TS_F_TS_MSG_IMPRINT_SET_ALGO                     0
#   define TS_F_TS_REQ_SET_MSG_IMPRINT                      0
#   define TS_F_TS_REQ_SET_NONCE                            0
#   define TS_F_TS_REQ_SET_POLICY_ID                        0
#   define TS_F_TS_RESP_CREATE_RESPONSE                     0
#   define TS_F_TS_RESP_CREATE_TST_INFO                     0
#   define TS_F_TS_RESP_CTX_ADD_FAILURE_INFO                0
#   define TS_F_TS_RESP_CTX_ADD_MD                          0
#   define TS_F_TS_RESP_CTX_ADD_POLICY                      0
#   define TS_F_TS_RESP_CTX_NEW                             0
#   define TS_F_TS_RESP_CTX_SET_ACCURACY                    0
#   define TS_F_TS_RESP_CTX_SET_CERTS                       0
#   define TS_F_TS_RESP_CTX_SET_DEF_POLICY                  0
#   define TS_F_TS_RESP_CTX_SET_SIGNER_CERT                 0
#   define TS_F_TS_RESP_CTX_SET_STATUS_INFO                 0
#   define TS_F_TS_RESP_GET_POLICY                          0
#   define TS_F_TS_RESP_SET_GENTIME_WITH_PRECISION          0
#   define TS_F_TS_RESP_SET_STATUS_INFO                     0
#   define TS_F_TS_RESP_SET_TST_INFO                        0
#   define TS_F_TS_RESP_SIGN                                0
#   define TS_F_TS_RESP_VERIFY_SIGNATURE                    0
#   define TS_F_TS_TST_INFO_SET_ACCURACY                    0
#   define TS_F_TS_TST_INFO_SET_MSG_IMPRINT                 0
#   define TS_F_TS_TST_INFO_SET_NONCE                       0
#   define TS_F_TS_TST_INFO_SET_POLICY_ID                   0
#   define TS_F_TS_TST_INFO_SET_SERIAL                      0
#   define TS_F_TS_TST_INFO_SET_TIME                        0
#   define TS_F_TS_TST_INFO_SET_TSA                         0
#   define TS_F_TS_VERIFY                                   0
#   define TS_F_TS_VERIFY_CERT                              0
#   define TS_F_TS_VERIFY_CTX_NEW                           0
# endif

/*
 * TS reason codes.
 */
#  define TS_R_BAD_PKCS7_TYPE                              132
#  define TS_R_BAD_TYPE                                    133
#  define TS_R_CANNOT_LOAD_CERT                            137
#  define TS_R_CANNOT_LOAD_KEY                             138
#  define TS_R_CERTIFICATE_VERIFY_ERROR                    100
#  define TS_R_COULD_NOT_SET_ENGINE                        127
#  define TS_R_COULD_NOT_SET_TIME                          115
#  define TS_R_DETACHED_CONTENT                            134
#  define TS_R_ESS_ADD_SIGNING_CERT_ERROR                  116
#  define TS_R_ESS_ADD_SIGNING_CERT_V2_ERROR               139
#  define TS_R_ESS_SIGNING_CERTIFICATE_ERROR               101
#  define TS_R_INVALID_NULL_POINTER                        102
#  define TS_R_INVALID_SIGNER_CERTIFICATE_PURPOSE          117
#  define TS_R_MESSAGE_IMPRINT_MISMATCH                    103
#  define TS_R_NONCE_MISMATCH                              104
#  define TS_R_NONCE_NOT_RETURNED                          105
#  define TS_R_NO_CONTENT                                  106
#  define TS_R_NO_TIME_STAMP_TOKEN                         107
#  define TS_R_PKCS7_ADD_SIGNATURE_ERROR                   118
#  define TS_R_PKCS7_ADD_SIGNED_ATTR_ERROR                 119
#  define TS_R_PKCS7_TO_TS_TST_INFO_FAILED                 129
#  define TS_R_POLICY_MISMATCH                             108
#  define TS_R_PRIVATE_KEY_DOES_NOT_MATCH_CERTIFICATE      120
#  define TS_R_RESPONSE_SETUP_ERROR                        121
#  define TS_R_SIGNATURE_FAILURE                           109
#  define TS_R_THERE_MUST_BE_ONE_SIGNER                    110
#  define TS_R_TIME_SYSCALL_ERROR                          122
#  define TS_R_TOKEN_NOT_PRESENT                           130
#  define TS_R_TOKEN_PRESENT                               131
#  define TS_R_TSA_NAME_MISMATCH                           111
#  define TS_R_TSA_UNTRUSTED                               112
#  define TS_R_TST_INFO_SETUP_ERROR                        123
#  define TS_R_TS_DATASIGN                                 124
#  define TS_R_UNACCEPTABLE_POLICY                         125
#  define TS_R_UNSUPPORTED_MD_ALGORITHM                    126
#  define TS_R_UNSUPPORTED_VERSION                         113
#  define TS_R_VAR_BAD_VALUE                               135
#  define TS_R_VAR_LOOKUP_FAILURE                          136
#  define TS_R_WRONG_CONTENT_TYPE                          114

# endif
#endif
