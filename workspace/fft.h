/* fft.h */
#ifndef FFT_H
#define FFT_H

#include <stddef.h>
#include "complex.h"

/* in-place Radix-2 FFT / IFFT (inverse=0 → FFT, inverse≠0 → IFFT) */
void fft_radix2(Complex *buf, size_t n, int inverse);

/* 실수 입력 → 복소 스펙트럼 (길이 n) */
void fft_real(const float *in, Complex *out, size_t n);

#endif /* FFT_H */

#ifndef M_PI
#define M_PI 3.14159265358979323846264338328
#endif
