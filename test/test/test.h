/* test.h  -  Foundation test library  -  Public Domain  -  2013 Mattias Jansson / Rampant Pixels
 *
 * This library provides a cross-platform foundation library in C11 providing basic support data types and
 * functions to write applications and games in a platform-independent fashion. The latest source code is
 * always available at
 *
 * https://github.com/rampantpixels/foundation_lib
 *
 * This library is put in the public domain; you can redistribute it and/or modify it without any restrictions.
 *
 */

#pragma once

#include <foundation/foundation.h>


#if defined( TEST_COMPILE ) && TEST_COMPILE
#  ifdef __cplusplus
#  define TEST_EXTERN extern "C"
#  else
#  define TEST_EXTERN extern
#  endif
#  define TEST_API
#else
#  ifdef __cplusplus
#  define TEST_EXTERN extern "C"
#  define TEST_API extern "C"
#  else
#  define TEST_EXTERN extern
#  define TEST_API extern
#  endif
#endif

#define FAILED_TEST ((void*)(uintptr_t)1)

typedef void* (* test_fn)( void );

TEST_API void test_add_test( test_fn test, const char* group_name, size_t group_length, const char* test_name, size_t test_length );
TEST_API int  test_run_all( void );

#if FOUNDATION_PLATFORM_IOS

TEST_API void  test_text_view_append( void* window, int tag, const char* msg, size_t length );

#endif

#define MAKE_TEST_FN( test_group, test_name ) FOUNDATION_PREPROCESSOR_JOIN( FOUNDATION_PREPROCESSOR_JOIN( test_group, test_name ), _fn )

#define DECLARE_TEST( test_group, test_name ) static void* MAKE_TEST_FN( test_group, test_name )( void )
#define ADD_TEST( test_group, test_name ) test_add_test( MAKE_TEST_FN( test_group, test_name ), STRING_CONST( FOUNDATION_PREPROCESSOR_TOSTRING( test_group ) ), STRING_CONST( FOUNDATION_PREPROCESSOR_TOSTRING( test_name ) ) )
#define RETURN_FAILED_TEST return FAILED_TEST

#define EXPECT_EQ( var, expect ) do { if( !((var) == (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_NE( var, expect ) do { if( ((var) == (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s == %s (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_GE( var, expect ) do { if( !((var) >= (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s < %s (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_GT( var, expect ) do { if( !((var) > (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s <= %s (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_LE( var, expect ) do { if( !((var) <= (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s > %s (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_LT( var, expect ) do { if( !((var) < (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s >= %s (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_TRUE( var ) do { if( !(var) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s is false (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_FALSE( var ) do { if( (var) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s is true (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)

#define EXPECT_EQ_MSG( var, expect, msg ) do { if( !((var) == (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_NE_MSG( var, expect, msg ) do { if( ((var) == (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s == %s (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_GE_MSG( var, expect, msg ) do { if( !((var) >= (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s < %s (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_GT_MSG( var, expect, msg ) do { if( !((var) > (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s <= %s (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_LE_MSG( var, expect, msg ) do { if( !((var) <= (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s > %s (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_LT_MSG( var, expect, msg ) do { if( !((var) < (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s >= %s (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_TRUE_MSG( var, msg ) do { if( !(var) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s is false (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_FALSE_MSG( var, msg ) do { if( (var) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s is true (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)

#define EXPECT_EQ_MSGFORMAT( var, expect, format, ... ) do { if( !((var) == (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_NE_MSGFORMAT( var, expect, format, ... ) do { if( ((var) == (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s == %s (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_GE_MSGFORMAT( var, expect, format, ... ) do { if( !((var) >= (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s < %s (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_GT_MSGFORMAT( var, expect, format, ... ) do { if( !((var) > (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s <= %s (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_LE_MSGFORMAT( var, expect, format, ... ) do { if( !((var) <= (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s > %s (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_LT_MSGFORMAT( var, expect, format, ... ) do { if( !((var) < (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s >= %s (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_TRUE_MSGFORMAT( var, format, ... ) do { if( !(var) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s is false (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_FALSE_MSGFORMAT( var, format, ... ) do { if( (var) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s is true (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)

#define EXPECT_INTEQ( var, expect ) do { if( !((var) == (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s (%d != %d) (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), (int)(var), (int)(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_INTNE( var, expect ) do { if(  ((var) == (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s == %s (%d == %d) (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), (int)(var), (int)(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_INTGE( var, expect ) do { if( !((var) >= (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s < %s (%d < %d) (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), (int)(var), (int)(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_INTGT( var, expect ) do { if( !((var)  > (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s <= %s (%d <= %d) (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), (int)(var), (int)(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_INTLE( var, expect ) do { if( !((var) <= (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s > %s (%d > %d) (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), (int)(var), (int)(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_INTLT( var, expect ) do { if( !((var)  < (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s >= %s (%d >= %d) (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), (int)(var), (int)(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)

#define EXPECT_SIZEEQ( var, expect ) do { if( !((var) == (expect)) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s (%" PRIsize " != %" PRIsize ") (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), (size_t)(var), (size_t)(expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)

#define EXPECT_STREQ_HELPER( var, varlen, expect, expectlen ) do { if( !string_equal( (var), (varlen), (expect), (expectlen) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s ('%.*s', '%.*s') (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), (int)(varlen), (var), (int)(expectlen), (expect), __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_STREQ_MSG_HELPER( var, varlen, expect, expectlen, msg ) do { if( !string_equal( (var), (varlen), (expect), (expectlen) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s ('%.*s', '%.*s') (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), (int)(varlen), (var), (int)(expectlen), (expect), __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_STREQ_MSGFORMAT_HELPER( var, varlen, expect, expectlen, format, ... ) do { if( !string_equal( (var), (varlen), (expect), (expectlen) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s ('%.*s', '%.*s') (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), (int)(varlen), (var), (int)(expectlen), (expect), __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)

#define EXPECT_STREQ( ... ) EXPECT_STREQ_HELPER( __VA_ARGS__ )
#define EXPECT_STREQ_MSG( ... ) EXPECT_STREQ_MSG_HELPER( __VA_ARGS__ )
#define EXPECT_STREQ_MSGFORMAT( ... ) EXPECT_STREQ_MSGFORMAT_HELPER( __VA_ARGS__ )

#define EXPECT_STRINGEQ( var, expect ) do { string_t lhs = (var); string_const_t rhs = (expect); if( !string_equal( STRING_ARGS( lhs ), STRING_ARGS( rhs ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_STRINGEQ_MSG( var, expect, msg ) do { string_t lhs = (var); string_const_t rhs = (expect); if( !string_equal( STRING_ARGS( lhs ), STRING_ARGS( rhs ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_STRINGEQ_MSGFORMAT( var, expect, format, ... ) do { string_t lhs = (var); string_const_t rhs = (expect); if( !string_equal( STRING_ARGS( lhs ), STRING_ARGS( rhs ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)

#define EXPECT_STRINGNE( var, expect ) do { string_t lhs = (var); string_const_t rhs = (expect); if( string_equal( STRING_ARGS( (lhs) ), STRING_ARGS( (rhs) ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s == %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_STRINGNE_MSG( var, expect, msg ) do { string_t lhs = (var); string_const_t rhs = (expect); if( string_equal( STRING_ARGS( lhs ), STRING_ARGS( rhs ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s == %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_STRINGNE_MSGFORMAT( var, expect, format, ... ) do { string_t lhs = (var); string_const_t rhs = (expect); if( string_equal( STRING_ARGS( (lhs) ), STRING_ARGS( (rhs) ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s == %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)

#define EXPECT_CONSTSTRINGEQ( var, expect ) do { string_const_t lhs = (var); string_const_t rhs = (expect); if( !string_equal( STRING_ARGS( lhs ), STRING_ARGS( rhs ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_CONSTSTRINGEQ_MSG( var, expect, msg ) do { string_const_t lhs = (var); string_const_t rhs = (expect); if( !string_equal( STRING_ARGS( lhs ), STRING_ARGS( rhs ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_CONSTSTRINGEQ_MSGFORMAT( var, expect, format, ... ) do { string_const_t lhs = (var); string_const_t rhs = (expect); if( !string_equal( STRING_ARGS( lhs ), STRING_ARGS( rhs ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)

#define EXPECT_CONSTSTRINGNE( var, expect ) do { string_const_t lhs = (var); string_const_t rhs = (expect); if( string_equal( STRING_ARGS( (lhs) ), STRING_ARGS( (rhs) ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s == %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u)" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__ ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_CONSTSTRINGNE_MSG( var, expect, msg ) do { string_const_t lhs = (var); string_const_t rhs = (expect); if( string_equal( STRING_ARGS( lhs ), STRING_ARGS( rhs ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s == %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u) : %s" ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__, msg ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_CONSTSTRINGNE_MSGFORMAT( var, expect, format, ... ) do { string_const_t lhs = (var); string_const_t rhs = (expect); if( string_equal( STRING_ARGS( (lhs) ), STRING_ARGS( (rhs) ) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s == %s ('%.*s':%" PRIsize ", '%.*s':%" PRIsize ") (at %s:%u) : " format ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), STRING_FORMAT( lhs ), lhs.length, STRING_FORMAT( rhs ), rhs.length, __FILE__, __LINE__, __VA_ARGS__ ); RETURN_FAILED_TEST; } } while(0)

#define EXPECT_REALZERO( var ) do { if( !math_realzero(var) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s is not zero real (at %s:%u): %.6" PRIREAL ), FOUNDATION_PREPROCESSOR_TOSTRING(var), __FILE__, __LINE__, (real)((var)) ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_REALONE( var ) do { if( !math_realone(var) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s is not one real (at %s:%u): %.6" PRIREAL ), FOUNDATION_PREPROCESSOR_TOSTRING(var), __FILE__, __LINE__, (real)((var)) ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_REALNE( var, expect ) do { if( math_realeq( (var), (expect), 10 ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s == %s real (at %s:%u): %.6" PRIREAL " : %.6" PRIREAL ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, (real)((var)), (real)((expect)) ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_REALEQ( var, expect ) do { if( !math_realeq( (var), (expect), 10 ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s real (at %s:%u): %.6" PRIREAL " : %.6" PRIREAL ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, (real)((var)), (real)((expect)) ); RETURN_FAILED_TEST; } } while(0)
#define EXPECT_REALEQULPS( var, expect, ulps ) do { if( !math_realeq( (var), (expect), (ulps) ) ) { log_warnf( HASH_TEST, WARNING_SUSPICIOUS, STRING_CONST( "Test failed, %s != %s real (at %s:%u): %.6" PRIREAL " : %.6" PRIREAL ), FOUNDATION_PREPROCESSOR_TOSTRING(var), FOUNDATION_PREPROCESSOR_TOSTRING(expect), __FILE__, __LINE__, (real)((var)), (real)((expect)) ); RETURN_FAILED_TEST; } } while(0)

//No inline to make sure compiler does not inline and reorder instructions
TEST_API void FOUNDATION_NOINLINE test_wait_for_threads_startup( const object_t* threads, size_t num_threads );
TEST_API void FOUNDATION_NOINLINE test_wait_for_threads_finish( const object_t* threads, size_t num_threads );
TEST_API void FOUNDATION_NOINLINE test_wait_for_threads_exit( const object_t* threads, size_t num_threads );

TEST_API void FOUNDATION_NOINLINE test_crash_handler( const char*, size_t length ) FOUNDATION_ATTRIBUTE( noreturn );
TEST_API bool FOUNDATION_NOINLINE test_should_terminate( void );

typedef struct _test_suite
{
	application_t       (*application)( void );
	memory_system_t     (*memory_system)( void );
    foundation_config_t (*config)( void );
	void                (*declare)( void );
	int                 (*initialize)( void );
	void                (*shutdown)( void );
} test_suite_t;

TEST_API test_suite_t  test_suite;
