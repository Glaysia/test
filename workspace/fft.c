/* fft.c */
#include "fft.h"
#include <math.h>
#include <stdlib.h>

/* ---------- 내부 유틸 ---------- */
static size_t reverse_bits(size_t x, unsigned int log2n)
{
    size_t n = 0;
    for (unsigned int i = 0; i < log2n; ++i) {
        n = (n << 1) | (x & 1);
        x >>= 1;
    }
    return n;
}

/* ---------- Radix-2 iterative FFT / IFFT ---------- */
void fft_radix2(Complex *buf, size_t n, int inverse)
{
    if (!buf || n == 0) return;

    /* 1) 비트 리버설 재배치 */
    unsigned int log2n = 0;
    for (size_t t = n; t > 1; t >>= 1) ++log2n;

    for (size_t i = 0; i < n; ++i) {
        size_t j = reverse_bits(i, log2n);
        if (j > i) {
            Complex tmp = buf[i];
            buf[i]      = buf[j];
            buf[j]      = tmp;
        }
    }

    /* 2) 버터플라이 단계 */
    const double sign = inverse ? 1.0 : -1.0;
    for (size_t len = 2; len <= n; len <<= 1) {
        double   ang = sign * 2.0 * M_PI / (double)len;
        Complex  wlen = { cos(ang), sin(ang) };

        for (size_t i = 0; i < n; i += len) {
            Complex w = { 1.0, 0.0 };

            for (size_t j = 0; j < len / 2; ++j) {
                Complex u = buf[i + j];
                Complex v = {
                    w.real * buf[i + j + len / 2].real - w.imag * buf[i + j + len / 2].imag,
                    w.real * buf[i + j + len / 2].imag + w.imag * buf[i + j + len / 2].real
                };

                /* u + v , u - v */
                buf[i + j].real             = u.real + v.real;
                buf[i + j].imag             = u.imag + v.imag;
                buf[i + j + len / 2].real   = u.real - v.real;
                buf[i + j + len / 2].imag   = u.imag - v.imag;

                /* w *= wlen */
                double tmp = w.real * wlen.real - w.imag * wlen.imag;
                w.imag     = w.real * wlen.imag + w.imag * wlen.real;
                w.real     = tmp;
            }
        }
    }

    /* 3) IFFT일 때 1/n 스케일링 */
    if (inverse) {
        for (size_t i = 0; i < n; ++i) {
            buf[i].real /= (double)n;
            buf[i].imag /= (double)n;
        }
    }
}

/* ---------- 실수 입력 래퍼 ---------- */
void fft_real(const float *in, Complex *out, size_t n)
{
    if (!in || !out || n == 0) return;

    /* 실수→복소 변환 (imag = 0) */
    for (size_t i = 0; i < n; ++i) {
        out[i].real = (double)in[i];
        out[i].imag = 0.0;
    }

    /* 전방 FFT 수행 */
    fft_radix2(out, n, 0);
}
