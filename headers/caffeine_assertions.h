#ifndef CAFFEINE_UTILS_ASSERTIONS
#define CAFFEINE_UTILS_ASSERTIONS
#include <assert.h>
#include <stdio.h>
#include "caffeine_macros.h"

#define cff_assert(EXP,...) for (unsigned char __assertion_flag__ = (EXP); !(__assertion_flag__) ; assert(__assertion_flag__) ) { __VA_ARGS__; }
#define cff_assert_msg(EXP, MSG) for (unsigned char __assertion_flag__ = (EXP); !(__assertion_flag__) ; assert(__assertion_flag__) ) { printf("[%s::%s]\n %s\n\n",CFF_FILENAME,__FUNCTION__,MSG); }

#define cff_assert_param_not_null(PARAM) cff_assert_msg((void*)(PARAM) != NULL, "Invalid Parameter Value: " #PARAM " couldn't be null" )
#define cff_assert_param_not_zero(PARAM) cff_assert_msg((PARAM) != 0, "Invalid Parameter Value: " #PARAM " couldn't be 0" )

#define cff_assert_param_equals(PARAM,VALUE) cff_assert_msg((PARAM) == (VALUE), "Invalid Parameter Value: " #PARAM " shout be equals to " #VALUE )
#define cff_assert_param_greater(PARAM,VALUE) cff_assert_msg((PARAM) > (VALUE), "Invalid Parameter Value: " #PARAM " shout be greater than " #VALUE )
#define cff_assert_param_greater_eq(PARAM,VALUE) cff_assert_msg((PARAM) >= (VALUE), "Invalid Parameter Value: " #PARAM " shout be equal or greater than " #VALUE )

#define cff_assert_param_less(PARAM,VALUE) cff_assert_msg((PARAM) < (VALUE), "Invalid Parameter Value: " #PARAM " shout be less than " #VALUE )
#define cff_assert_param_less_eq(PARAM,VALUE) cff_assert_msg((PARAM) <= (VALUE), "Invalid Parameter Value: " #PARAM " shout be equal or less than " #VALUE )

#define cff_assert_not_null(PARAM) cff_assert_msg((void*)(PARAM) != NULL, "Invalid Value: " #PARAM " couldn't be null" )
#define cff_assert_not_zero(PARAM) cff_assert_msg((PARAM) != 0, "Invalid Value: " #PARAM " couldn't be 0" )

#define cff_assert_equals(PARAM,VALUE) cff_assert_msg((PARAM) == (VALUE), "Invalid Value: " #PARAM " shout be equals to " #VALUE )
#define cff_assert_greater(PARAM,VALUE) cff_assert_msg((PARAM) > (VALUE), "Invalid Value: " #PARAM " shout be greater than " #VALUE )
#define cff_assert_greater_eq(PARAM,VALUE) cff_assert_msg((PARAM) >= (VALUE), "Invalid Value: " #PARAM " shout be equal or greater than " #VALUE )

#define cff_assert_less(PARAM,VALUE) cff_assert_msg((PARAM) < (VALUE), "Invalid Value: " #PARAM " shout be less than " #VALUE )
#define cff_assert_less_eq(PARAM,VALUE) cff_assert_msg((PARAM) <= (VALUE), "Invalid Value: " #PARAM " shout be equal or less than " #VALUE )

#endif