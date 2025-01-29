#include <check.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "./s21_math.h"

#define TOLERANCE 1e-5
#define M_PI 3.14159265358979323846

// Test case for the abs function
START_TEST(test_abs_positive) {
  // Test when x is a positive number
  ck_assert_int_eq(s21_abs(5), abs(5));
  ck_assert_int_eq(s21_abs(100), abs(100));
  ck_assert_int_eq(s21_abs(0), abs(0));
}

END_TEST

START_TEST(test_abs_negative) {
  // Test when x is a negative number
  ck_assert_int_eq(s21_abs(-5), abs(5));
  ck_assert_int_eq(s21_abs(-100), abs(100));
}

END_TEST

START_TEST(test_abs_min_int) {
  // Test with the minimum negative integer
  ck_assert_int_eq(s21_abs(INT_MIN),
                   abs(INT_MIN));  // Expect INT_MIN due to overflow
}

END_TEST

// Test case for the acos function
START_TEST(test_acos_positive) {
  // Test when x is a positive number less than or equal to 1
  ck_assert_double_eq_tol(s21_acos(0.5), acos(0.5), TOLERANCE);
}

END_TEST

START_TEST(test_acos_negative) {
  // Test when x is a negative number
  // The standard acos returns NaN for values outside the range [-1, 1]
  ck_assert(isnan(s21_acos(-1.5)));
}

END_TEST

START_TEST(test_acos_out_of_range) {
  // Test when x is greater than 1
  // The standard acos returns NaN for values outside the range [-1, 1]
  ck_assert(isnan(s21_acos(1.5)));
}

END_TEST

// Test case for the asin function
START_TEST(test_asin_positive) {
  // Test when x is a positive number less than or equal to 1
  ck_assert_double_eq_tol(s21_asin(0.5), asin(0.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_asin(1), asin(1), TOLERANCE);
}

END_TEST

START_TEST(test_asin_negative) {
  // Test when x is a negative number greater than or equal to -1
  ck_assert_double_eq_tol(s21_asin(-0.5), asin(-0.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_asin(-1), asin(-1), TOLERANCE);
}

END_TEST

START_TEST(test_asin_out_of_range) {
  // Test when x is greater than 1
  // The standard asin returns NaN for values outside the range [-1, 1]
  ck_assert(isnan(s21_asin(1.5)));
}

START_TEST(test_asin_below_range) {
  // Test when x is less than -1
  // The standard asin returns NaN for values outside the range [-1, 1]
  ck_assert(isnan(s21_asin(-1.5)));
}

END_TEST

START_TEST(test_asin_special_cases) {
  // Test special cases: asin of NaN
  ck_assert(isnan(s21_asin(NAN)));
}
END_TEST

// Test case for the ceil function
START_TEST(test_ceil_positive) {
  // Test when x is a positive decimal number
  ck_assert_double_eq_tol(s21_ceil(3.14), ceil(3.14), TOLERANCE);
  ck_assert_double_eq_tol(s21_ceil(7.8), ceil(7.8), TOLERANCE);
}
END_TEST

START_TEST(test_ceil_negative) {
  // Test when x is a negative decimal number
  ck_assert_double_eq_tol(s21_ceil(-2.5), ceil(-2.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_ceil(-9.99), ceil(-9.99), TOLERANCE);
}
END_TEST

START_TEST(test_ceil_whole_number) {
  // Test when x is a positive or negative whole number
  ck_assert_double_eq_tol(s21_ceil(5.0), ceil(5.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_ceil(-8.0), ceil(-8.0), TOLERANCE);
}
END_TEST

START_TEST(test_ceil_zero) {
  // Test when x is zero
  ck_assert_double_eq_tol(s21_ceil(0.0), ceil(0.0), TOLERANCE);
}
END_TEST

START_TEST(test_ceil_divide_by_zero) {
  ck_assert_double_eq(s21_ceil(1. / 0.0), ceil(1. / 0.0));
  ck_assert_double_eq(s21_ceil(-1. / 0.0), ceil(-1. / 0.0));
}
END_TEST

// Test case for the atan function
START_TEST(test_atan_positive) {
  // Test when x is a positive number
  ck_assert_double_eq_tol(s21_atan(0.5), atan(0.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_atan(1.45), atan(1.45), TOLERANCE);
  ck_assert_double_eq_tol(s21_atan(1e7), atan(1e7), TOLERANCE);
}

END_TEST

START_TEST(test_atan_negative) {
  // Test when x is a negative number
  ck_assert_double_eq_tol(s21_atan(-0.5), atan(-0.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_atan(-1.45), atan(-1.45), TOLERANCE);
}

END_TEST

START_TEST(test_atan_zero) {
  // Test when x is zero
  ck_assert_double_eq_tol(s21_atan(0.0), atan(0.0), TOLERANCE);
}

END_TEST

START_TEST(test_atan_special_cases) {
  // Test special cases: atan of NaN
  ck_assert(isnan(s21_atan(NAN)));
}

END_TEST

START_TEST(test_atan_infinite) {
  // Test when x is infinity
  ck_assert_double_eq_tol(s21_atan(INFINITY), atan(INFINITY), TOLERANCE);
}

END_TEST

START_TEST(test_atan_one) {
  // Test when x is one
  ck_assert_double_eq_tol(s21_atan(1), atan(1), TOLERANCE);
}

END_TEST

// Test case for the cos function
START_TEST(test_cos_positive) {
  // Test when x is a positive angle in radians
  ck_assert_double_eq_tol(s21_cos(0.5), cos(0.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_cos(1.2), cos(1.2), TOLERANCE);
}
END_TEST

START_TEST(test_cos_negative) {
  // Test when x is a negative angle in radians
  ck_assert_double_eq_tol(s21_cos(-0.5), cos(-0.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_cos(-1.2), cos(-1.2), TOLERANCE);
}
END_TEST

START_TEST(test_cos_quadrant) {
  // Test angles in different quadrants
  ck_assert_double_eq_tol(s21_cos(M_PI / 4), cos(M_PI / 4), TOLERANCE);
  ck_assert_double_eq_tol(s21_cos(3 * M_PI / 4), cos(3 * M_PI / 4), TOLERANCE);
  ck_assert_double_eq_tol(s21_cos(-2 * M_PI / 3), cos(-2 * M_PI / 3),
                          TOLERANCE);
}
END_TEST

START_TEST(test_cos_special_cases) {
  // Test special cases: cos of NaN
  ck_assert(isnan(s21_cos(NAN)));
}
END_TEST

// Test case for the exp function
START_TEST(test_exp_positive) {
  // Test when x is a positive number
  ck_assert_double_eq_tol(s21_exp(2.0), exp(2.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_exp(0.5), exp(0.5), TOLERANCE);
}
END_TEST

START_TEST(test_exp_negative) {
  // Test when x is a negative number
  ck_assert_double_eq_tol(s21_exp(-1.0), exp(-1.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_exp(-2.5), exp(-2.5), TOLERANCE);
}
END_TEST

START_TEST(test_exp_zero) {
  // Test when x is zero
  ck_assert_double_eq_tol(s21_exp(0.0), exp(0.0), TOLERANCE);
}
END_TEST

START_TEST(test_exp_special_cases) {
  // Test special cases: exp of NaN
  ck_assert(isnan(s21_exp(NAN)));
}
END_TEST

START_TEST(test_exp_infinity) {
  // Test when x is infinity
  ck_assert_double_eq(s21_exp(INFINITY), exp(INFINITY));
  ck_assert_double_eq(s21_exp(-INFINITY), exp(-INFINITY));
}
END_TEST

// Test case for the fabs function
START_TEST(test_fabs_positive) {
  // Test when x is a positive number
  ck_assert_double_eq_tol(s21_fabs(5.0), fabs(5.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_fabs(100.123), fabs(100.123), TOLERANCE);
}

END_TEST

START_TEST(test_fabs_negative) {
  // Test when x is a negative number
  ck_assert_double_eq_tol(s21_fabs(-7.5), fabs(-7.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_fabs(-123.456), fabs(-123.456), TOLERANCE);
}

END_TEST

START_TEST(test_fabs_zero) {
  // Test when x is zero
  ck_assert_double_eq_tol(s21_fabs(0.0), fabs(0.0), TOLERANCE);
}

END_TEST

START_TEST(test_fabs_special_cases) {
  // Test special cases: fabs of NaN and infinity
  ck_assert(isnan(s21_fabs(NAN)));
  ck_assert(isinf(s21_fabs(INFINITY)));
  ck_assert(isinf(s21_fabs(-INFINITY)));
}

END_TEST

// Test case for the floor function
START_TEST(test_floor_positive) {
  // Test when x is a positive decimal number
  ck_assert_double_eq_tol(s21_floor(3.14), floor(3.14), TOLERANCE);
  ck_assert_double_eq_tol(s21_floor(7.8), floor(7.8), TOLERANCE);
}

END_TEST

START_TEST(test_floor_negative) {
  // Test when x is a negative decimal number
  ck_assert_double_eq_tol(s21_floor(-2.5), floor(-2.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_floor(-9.99), floor(-9.99), TOLERANCE);
}

END_TEST

START_TEST(test_floor_whole_number) {
  // Test when x is a positive or negative whole number
  ck_assert_double_eq_tol(s21_floor(5.0), floor(5.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_floor(-8.0), floor(-8.0), TOLERANCE);
}

END_TEST

START_TEST(test_floor_zero) {
  // Test when x is zero
  ck_assert_double_eq_tol(s21_floor(0.0), floor(0.0), TOLERANCE);
}

END_TEST

START_TEST(test_floor_divide_by_zero) {
  ck_assert_double_eq(s21_floor(1. / 0.0), floor(1. / 0.0));
  ck_assert_double_eq(s21_floor(-1. / 0.0), floor(-1. / 0.0));
}

END_TEST

// Test case for the fmod function
START_TEST(test_fmod_positive) {
  // Test when x is a positive number and y is a positive number
  ck_assert_double_eq_tol(s21_fmod(10.5, 3.0), fmod(10.5, 3.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_fmod(15.7, 4.2), fmod(15.7, 4.2), TOLERANCE);
}

END_TEST

START_TEST(test_fmod_negative) {
  // Test when x is a negative number and y is a positive number
  ck_assert_double_eq_tol(s21_fmod(-8.5, 2.0), fmod(-8.5, 2.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_fmod(-12.9, 5.3), fmod(-12.9, 5.3), TOLERANCE);
}

END_TEST

START_TEST(test_fmod_mixed) {
  // Test when x is a positive number and y is a negative number
  ck_assert_double_eq_tol(s21_fmod(7.5, -2.0), fmod(7.5, -2.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_fmod(11.2, -3.5), fmod(11.2, -3.5), TOLERANCE);
}

END_TEST

START_TEST(test_fmod_zero) {
  // Test when x is zero and y is a positive number
  ck_assert_double_eq_tol(s21_fmod(0.0, 5.0), fmod(0.0, 5.0), TOLERANCE);
}

END_TEST

START_TEST(test_fmod_both_zero) {
  // Test when both x and y are zero
  ck_assert(isnan(s21_fmod(0.0, 0.0)));
}

END_TEST

START_TEST(test_fmod_infinity) {
  // Test when x infinity
  ck_assert_double_eq_tol(s21_fmod(3.3, INFINITY), fmod(3.3, INFINITY),
                          TOLERANCE);
  ck_assert_double_eq_tol(s21_fmod(3.3, -INFINITY), fmod(3.3, -INFINITY),
                          TOLERANCE);
  ck_assert(isnan(s21_fmod(INFINITY, 3.3)));
  ck_assert(isnan(s21_fmod(-INFINITY, 3.3)));
}

END_TEST

// Test case for the log function
START_TEST(test_log_positive) {
  // Test when x is a positive number
  ck_assert_double_eq_tol(s21_log(2.0), log(2.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_log(5.0), log(5.0), TOLERANCE);
}

END_TEST

START_TEST(test_log_one) {
  // Test when x is 1.0
  // The standard log of 1.0 is 0.0
  ck_assert_double_eq_tol(s21_log(1.0), log(1.0), TOLERANCE);
}

END_TEST

START_TEST(test_log_negative) {
  // Test when x is a negative number
  // The standard log returns NaN for negative numbers
  ck_assert(isnan(s21_log(-2.0)));
}

END_TEST

START_TEST(test_log_zero) {
  // Test when x is 0.0
  // The standard log of 0.0 is negative infinity
  ck_assert(isinf(s21_log(0.0)));
  ck_assert(s21_log(0.0) < 0.0);
}

END_TEST

START_TEST(test_log_infinity) {
  ck_assert_double_eq(s21_log(INFINITY), log(INFINITY));
  ck_assert(isnan(s21_log(-INFINITY)));
}

END_TEST

// Test case for the pow function
START_TEST(test_pow_positive) {
  // Test when base is a positive number and exponent is a positive integer
  ck_assert_double_eq_tol(s21_pow(2.0, 3.0), pow(2.0, 3.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_pow(5.0, 2.0), pow(5.0, 2.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_pow(5.3, 2.4), pow(5.3, 2.4), TOLERANCE);
  ck_assert_double_eq_tol(s21_pow(1.0, 0.1), pow(1.0, 0.1), TOLERANCE);
}

END_TEST

START_TEST(test_pow_zero_exponent) {
  // Test when base is any non-zero number and exponent is 0.0
  // The standard pow of any number to the power of 0 is 1.0
  ck_assert_double_eq_tol(s21_pow(2.0, 0.0), pow(2.0, 0.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_pow(5.0, 0.0), pow(5.0, 0.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_pow(5.0, 0.1), pow(5.0, 0.1), TOLERANCE);
}

END_TEST

START_TEST(test_pow_negative_exponent) {
  // Test when base is any non-zero number and exponent is a negative integer
  ck_assert_double_eq_tol(s21_pow(2.0, -2.0), pow(2.0, -2.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_pow(5.0, -3.2), pow(5.0, -3.2), TOLERANCE);
  ck_assert_double_eq_tol(s21_pow(1.0, -3.3), pow(1.0, -3.3), TOLERANCE);
}

END_TEST

START_TEST(test_pow_zero_base) {
  // Test when base is 0.0 and exponent is any non-zero number
  // The standard pow of 0 to any power (except 0) is 0.0
  ck_assert_double_eq_tol(s21_pow(0.0, 3.0), pow(0.0, 3.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_pow(0.0, 3.2), pow(0.0, 3.2), TOLERANCE);
  ck_assert_double_eq(s21_pow(0.0, -3.2), INFINITY);
}

END_TEST

START_TEST(test_pow_zero_base_zero_exponent) {
  // Test when base is 0.0 and exponent is 0.0
  ck_assert_double_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), TOLERANCE);
}

END_TEST

START_TEST(test_pow_negative_base) {
  ck_assert_double_eq_tol(s21_pow(-1, 1), pow(-1, 1), TOLERANCE);
}

END_TEST

START_TEST(test_pow_special_cases) {
  ck_assert_double_eq(s21_pow(INFINITY, 2), pow(INFINITY, 2));
  ck_assert_double_eq(s21_pow(-INFINITY, 2), pow(-INFINITY, 2));
  ck_assert_double_eq(s21_pow(2, INFINITY), pow(2, INFINITY));
  ck_assert_double_eq(s21_pow(2, -INFINITY), pow(2, -INFINITY));
  ck_assert(isnan(s21_pow(NAN, 2)));
  ck_assert(isnan(s21_pow(2, NAN)));
}

END_TEST

// Test case for the sin function
START_TEST(test_sin_positive) {
  // Test when x is a positive angle in radians
  ck_assert_double_eq_tol(s21_sin(0.5), sin(0.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_sin(1.2), sin(1.2), TOLERANCE);
}

END_TEST

START_TEST(test_sin_negative) {
  // Test when x is a negative angle in radians
  ck_assert_double_eq_tol(s21_sin(-0.5), sin(-0.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_sin(-1.2), sin(-1.2), TOLERANCE);
}

END_TEST

START_TEST(test_sin_zero) {
  // Test when x is zero
  ck_assert_double_eq_tol(s21_sin(0.0), sin(0.0), TOLERANCE);
}

END_TEST

START_TEST(test_sin_special_cases) {
  // Test special cases: sin of NaN
  ck_assert(isnan(s21_sin(NAN)));
}

END_TEST

// Test case for the sqrt function
START_TEST(test_sqrt_positive) {
  // Test when x is a positive number
  ck_assert_double_eq_tol(s21_sqrt(4.0), sqrt(4.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_sqrt(9.0), sqrt(9.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_sqrt(25.0), sqrt(25.0), TOLERANCE);
  ck_assert_double_eq_tol(s21_sqrt(25.1), sqrt(25.1), TOLERANCE);
}

END_TEST

START_TEST(test_sqrt_zero) {
  // Test when x is zero
  ck_assert_double_eq_tol(s21_sqrt(0.0), sqrt(0.0), TOLERANCE);
}

END_TEST

START_TEST(test_sqrt_negative) {
  // Test when x is a negative number
  // The standard sqrt returns NaN for negative numbers
  ck_assert(isnan(s21_sqrt(-1.0)));
  ck_assert(isnan(s21_sqrt(-1.3)));
}

END_TEST

START_TEST(test_sqrt_special_cases) {
  // Test special cases: sqrt of NaN
  ck_assert(isnan(s21_sqrt(NAN)));
}

END_TEST

// Test case for the tan function
START_TEST(test_tan_positive) {
  // Test when x is a positive angle in radians
  ck_assert_double_eq_tol(s21_tan(0.5), tan(0.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_tan(1.2), tan(1.2), TOLERANCE);
}

END_TEST

START_TEST(test_tan_negative) {
  // Test when x is a negative angle in radians
  ck_assert_double_eq_tol(s21_tan(-0.5), tan(-0.5), TOLERANCE);
  ck_assert_double_eq_tol(s21_tan(-1.2), tan(-1.2), TOLERANCE);
}

END_TEST

START_TEST(test_tan_special_cases) {
  // Test special cases: tan of NaN and infinity
  ck_assert(isnan(s21_tan(NAN)));
  ck_assert(isnan(s21_tan(INFINITY)));
  ck_assert(isnan(s21_tan(-INFINITY)));
  ck_assert_double_eq_tol(s21_tan(3.14159265358979323846 / 2),
                          tan(3.14159265358979323846 / 2), TOLERANCE);
}

END_TEST

Suite *abs_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("abs");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_abs_positive);
  tcase_add_test(tc_core, test_abs_negative);
  tcase_add_test(tc_core, test_abs_min_int);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *acos_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("acos");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_acos_positive);
  tcase_add_test(tc_core, test_acos_negative);
  tcase_add_test(tc_core, test_acos_out_of_range);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *asin_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("asin");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_asin_positive);
  tcase_add_test(tc_core, test_asin_negative);
  tcase_add_test(tc_core, test_asin_out_of_range);
  tcase_add_test(tc_core, test_asin_below_range);
  tcase_add_test(tc_core, test_asin_special_cases);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *atan_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("atan");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_atan_positive);
  tcase_add_test(tc_core, test_atan_negative);
  tcase_add_test(tc_core, test_atan_zero);
  tcase_add_test(tc_core, test_atan_special_cases);
  tcase_add_test(tc_core, test_atan_infinite);
  tcase_add_test(tc_core, test_atan_one);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *ceil_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("ceil");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_ceil_positive);
  tcase_add_test(tc_core, test_ceil_negative);
  tcase_add_test(tc_core, test_ceil_whole_number);
  tcase_add_test(tc_core, test_ceil_zero);
  tcase_add_test(tc_core, test_ceil_divide_by_zero);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *cos_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("cos");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_cos_positive);
  tcase_add_test(tc_core, test_cos_negative);
  tcase_add_test(tc_core, test_cos_quadrant);
  tcase_add_test(tc_core, test_cos_special_cases);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *exp_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("exp");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_exp_positive);
  tcase_add_test(tc_core, test_exp_negative);
  tcase_add_test(tc_core, test_exp_zero);
  tcase_add_test(tc_core, test_exp_special_cases);
  tcase_add_test(tc_core, test_exp_infinity);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *fabs_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("fabs");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_fabs_positive);
  tcase_add_test(tc_core, test_fabs_negative);
  tcase_add_test(tc_core, test_fabs_zero);
  tcase_add_test(tc_core, test_fabs_special_cases);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *floor_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("floor");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_floor_positive);
  tcase_add_test(tc_core, test_floor_negative);
  tcase_add_test(tc_core, test_floor_whole_number);
  tcase_add_test(tc_core, test_floor_zero);
  tcase_add_test(tc_core, test_floor_divide_by_zero);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *fmod_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("fmod");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_fmod_positive);
  tcase_add_test(tc_core, test_fmod_negative);
  tcase_add_test(tc_core, test_fmod_mixed);
  tcase_add_test(tc_core, test_fmod_zero);
  tcase_add_test(tc_core, test_fmod_both_zero);
  tcase_add_test(tc_core, test_fmod_infinity);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *log_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("log");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_log_positive);
  tcase_add_test(tc_core, test_log_one);
  tcase_add_test(tc_core, test_log_negative);
  tcase_add_test(tc_core, test_log_zero);
  tcase_add_test(tc_core, test_log_infinity);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *pow_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("pow");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_pow_positive);
  tcase_add_test(tc_core, test_pow_zero_exponent);
  tcase_add_test(tc_core, test_pow_negative_exponent);
  tcase_add_test(tc_core, test_pow_zero_base);
  tcase_add_test(tc_core, test_pow_zero_base_zero_exponent);
  tcase_add_test(tc_core, test_pow_negative_base);
  tcase_add_test(tc_core, test_pow_special_cases);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *sin_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("sin");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_sin_positive);
  tcase_add_test(tc_core, test_sin_negative);
  tcase_add_test(tc_core, test_sin_zero);
  tcase_add_test(tc_core, test_sin_special_cases);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *sqrt_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("sqrt");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_sqrt_positive);
  tcase_add_test(tc_core, test_sqrt_zero);
  tcase_add_test(tc_core, test_sqrt_negative);
  tcase_add_test(tc_core, test_sqrt_special_cases);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *tan_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("tan");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_tan_positive);
  tcase_add_test(tc_core, test_tan_negative);
  tcase_add_test(tc_core, test_tan_special_cases);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  int number_failed;
  Suite *abs_s, *acos_s, *asin_s, *atan_s, *ceil_s, *cos_s, *exp_s, *fabs_s,
      *floor_s, *fmod_s, *log_s, *pow_s, *sin_s, *sqrt_s, *tan_s;
  SRunner *sr;

  abs_s = abs_suite();
  acos_s = acos_suite();
  asin_s = asin_suite();
  atan_s = atan_suite();
  ceil_s = ceil_suite();
  cos_s = cos_suite();
  exp_s = exp_suite();
  fabs_s = fabs_suite();
  floor_s = floor_suite();
  fmod_s = fmod_suite();
  log_s = log_suite();
  pow_s = pow_suite();
  sin_s = sin_suite();
  sqrt_s = sqrt_suite();
  tan_s = tan_suite();

  sr = srunner_create(abs_s);
  srunner_add_suite(sr, acos_s);
  srunner_add_suite(sr, asin_s);
  srunner_add_suite(sr, atan_s);
  srunner_add_suite(sr, ceil_s);
  srunner_add_suite(sr, cos_s);
  srunner_add_suite(sr, exp_s);
  srunner_add_suite(sr, fabs_s);
  srunner_add_suite(sr, floor_s);
  srunner_add_suite(sr, fmod_s);
  srunner_add_suite(sr, log_s);
  srunner_add_suite(sr, pow_s);
  srunner_add_suite(sr, sin_s);
  srunner_add_suite(sr, sqrt_s);
  srunner_add_suite(sr, tan_s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}