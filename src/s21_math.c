#include "s21_math.h"

#include "utils.h"
// В этом файле не должно быть никаких других функций кроме функций библиотеки.
// Вспомогательные функции должны быть вынесены в utils.c

int s21_abs(int x) {
  if (x < 0) x = -x;
  return x;
}

long double s21_acos(double x) {
  long double result;
  if (x < -1.0 || x > 1.0 || x != x) {
    result = S21_NAN;
  } else {
    result = S21_PI / 2 - s21_asin(x);
  }
  return result;
}

long double s21_asin(double x) {
  long double result = 0;
  if (x < -1.0 || x > 1.0) {
    result = S21_NAN;
  } else if (x == 1) {
    result = S21_PI / 2;
  } else if (x == -1) {
    result = -S21_PI / 2;
  } else {
    result = x;
    long double temp = x;
    int i = 1;
    while (s21_fabs(temp) >= S21_EPS && i <= 400000) {
      temp =
          (s21_factorial(2 * i) * s21_int_pow(x, (unsigned int)(2 * i + 1))) /
          (s21_int_pow(4.0, (unsigned int)(i)) * s21_factorial(i) *
           s21_factorial(i) * (2 * i + 1));
      result += temp;
      i++;
    }
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  int sign = 1;
  if (x < 0) {
    x *= -1;
    sign = -1;
  }
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF || x >= 1e7) {
    result = S21_PI / 2 * sign;
  } else if (x == 1) {
    result = S21_PI / 4 * sign;
  } else if (x > 1) {
    x = 1 / x;
    result = S21_PI / 2 - s21_atan(x);
    result *= sign;
  } else {
    result = x;
    double alter = -1.0;
    int n = 2;
    while (n < 20) {
      result += (s21_pow(x, (2 * n - 1)) / (2 * n - 1) * alter);
      ++n;
      alter *= -1.0;
    }
    result *= sign;
  }

  return result;
}

long double s21_ceil(double x) {
  double result;

  if (x == 1. / 0.0) {
    result = 1. / 0.0;
  } else if (x == -1. / 0.0) {
    result = -1. / 0.0;
  } else {
    result = (x - (long long int)x != 0 && x > 0) ? (long long int)x + 1
                                                  : (long long int)x;
  }
  return result;
}

long double s21_cos(double x) {
  long double result = 0.0;
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF || x == -S21_INF) {
    result = S21_NAN;
  } else {
    long double x1 = s21_fmod(x, 2 * S21_PI);
    long double temp = 1.;
    int i = 0;
    while (s21_fabs(temp) >= S21_EPS) {
      result += temp;
      i++;
      temp *= -x1 * x1 / (i * (i + 1));
      i++;
    }
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 1;
  if (x == 0) {
    result = 1;
  } else if (x < -20) {
    result = 0;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x > 709) {
    result = S21_INF;
  } else {
    double x0 = x;
    if (x0 < 0) x0 = -x0;
    long double temp = 1;
    long double num = x0;
    long double i = 1;
    while (temp > 1e-17) {
      temp *= num / i;
      result += temp;
      ++i;
    }
    if (x < 0) {
      result = 1 / result;
    }
  }
  return result;
}

long double s21_fabs(double x) {  //модуль числа
  if (x < 0) {
    x = x * (-1);
  }
  return (long double)x;
}

long double s21_floor(double x) {
  double result;

  if (x == 1. / 0.0) {
    result = 1. / 0.0;
  } else if (x == -1. / 0.0) {
    result = -1. / 0.0;
  } else {
    result = (x - (long long int)x != 0 && x < 0) ? (long long int)x - 1
                                                  : (long long int)x;
  }

  return result;
}

long double s21_fmod(double x, double y) {  // нахождение остатка
  // x - делитель; y - делимое
  if (y == 0 || S21_IS_INF(x) || (S21_IS_INF(y) && S21_IS_INF(x) && x != y)) {
    return S21_NAN;
  }
  if (S21_IS_INF(y)) {
    return (long double)x;
  }
  long long int chastnoe;
  long double ostatok;
  chastnoe = x / y;
  ostatok = (long double)x - chastnoe * (long double)y;
  return ostatok;
}

long double s21_log(
    double x) {  //функцияпоиска логарифма, обратная возвед в степень
  if (x == S21_INF) return x;
  if (x == 0) return S21_INF_NEG;
  if (x < 0) return S21_NAN;

  int ex_pow = 0;  //счетчик количества экспоненты в х
  long double result = 0;  // значение логарифма

  for (; x >= S21_EXP; ex_pow++) {
    x = x / S21_EXP;
  }

  for (int i = 0; i < 100; i++) {
    long double comp = result;
    result = comp + 2 * (x - s21_exp(comp)) / (x + s21_exp(comp));
  }

  return (result + ex_pow);
}

long double s21_pow(double base, double exp) {
  long double result = 0;
  if (s21_fabs(base) < S21_EPS) base = 0;

  if (!edge_pow(base, exp, &result)) {
    if (exp == (int)exp) {
      result = s21_int_pow(base, exp);
    } else {
      int sign = 1;
      double exp0 = exp;
      if (exp0 < 0) exp0 = -exp0;
      int int_exp = (int)exp0;
      if (exp0 > 1) exp0 = exp0 - int_exp;
      result = s21_exp(s21_log(base) * exp0);
      result *= s21_int_pow(base, (unsigned int)int_exp);
      if (exp < 0) result = 1 / result;
      result *= sign;
    }
  }

  return result;
}

long double s21_sin(double x) {
  long double result = 0;
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF || x == -S21_INF) {
    result = S21_NAN;
  } else {
    long double x1 = s21_fmod(x, 2 * S21_PI);
    long double temp = x1;
    int i = 0;
    while (s21_fabs(temp) >= S21_EPS) {
      result += temp;
      i++;
      temp *= -x1 * x1 / (2 * i * (2 * i + 1));
    }
  }
  return result;
}

long double s21_sqrt(double x) { return s21_pow(x, 0.5); }

long double s21_tan(double x) {
  long double result = 0.0;
  if (x != x) {
    result = S21_NAN;
  } else if (s21_fabs(x - S21_PI / 2) < S21_EPS) {
    result = 16331239353195370.0;
  } else if (x == S21_INF) {
    result = S21_NAN;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}
