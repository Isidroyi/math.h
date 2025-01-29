#include "utils.h"

#include "s21_math.h"

long int s21_factorial(int x) {
  long int res = 1;
  for (int i = 1; i <= x; i++) {
    res *= i;
  }
  return res;
}

long double s21_int_pow(double base, double exp) {
  long double res = 1.0;

  if (exp > 0.0) {
    for (int i = 0; i < exp; ++i) {
      res *= base;
    }
  } else {
    for (int i = 0; i > exp; --i) {
      res /= base;
    }
  }

  return res;
}

int edge_pow(double base, double exp, long double *result) {
  int edge = 0;

  if ((base == 0.0 && exp > 0) ||
      (exp < 0 && (base == S21_INF || base == -S21_INF)) ||
      (exp == -S21_INF && s21_fabs(base) > 1)) {
    edge = 1;
    *result = 0.0;
  } else if (((base == S21_INF || base == -S21_INF) && exp > 0) ||
             (exp == S21_INF && s21_fabs(base) > 1) ||
             (exp == -S21_INF && s21_fabs(base) < 1) ||
             (base == 0 && exp < 0)) {
    edge = 1;
    *result = S21_INF;
  } else if ((exp == 0) || (base == 1 || (base == -1 && (exp == S21_INF ||
                                                         exp == -S21_INF)))) {
    edge = 1;
    *result = 1.0;
  } else if ((exp != exp || base != base) ||
             (base < 0 && ((int)exp) - exp != 0)) {
    edge = 1;
    *result = S21_NAN;
  }
  return edge;
}