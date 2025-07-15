// complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

/* 생성자 */
Complex complex_make(double real, double imag);

/* 산술 연산 */
Complex complex_add(Complex a, Complex b);
Complex complex_sub(Complex a, Complex b);
Complex complex_mul(Complex a, Complex b);
Complex complex_div(Complex a, Complex b);

/* 켤레 */
Complex complex_conj(Complex z);

/* 출력 */
void    complex_print(Complex z);

#endif /* COMPLEX_H */
