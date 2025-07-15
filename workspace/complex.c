// complex.c
#include "complex.h"

/* 생성자 */
Complex complex_make(double real, double imag) {
    return (Complex){ real, imag };
}

/* 덧셈 */
Complex complex_add(Complex a, Complex b) {
    return (Complex){ a.real + b.real, a.imag + b.imag };
}

/* 뺄셈 */
Complex complex_sub(Complex a, Complex b) {
    return (Complex){ a.real - b.real, a.imag - b.imag };
}

/* 곱셈 */
Complex complex_mul(Complex a, Complex b) {
    return (Complex){
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

/* 나눗셈 */
Complex complex_div(Complex a, Complex b) {
    double denom = b.real * b.real + b.imag * b.imag;
    return (Complex){
        (a.real * b.real + a.imag * b.imag) / denom,
        (a.imag * b.real - a.real * b.imag) / denom
    };
}

/* 켤레 */
Complex complex_conj(Complex z) {
    return (Complex){ z.real, -z.imag };
}

/* 출력: "a + bi" 또는 "a - bi" 형태 */
void complex_print(Complex z) {
    printf("%.2f %c %.2fi\n",
           z.real,
           (z.imag < 0 ? '-' : '+'),
           (z.imag < 0 ? -z.imag : z.imag));
}
