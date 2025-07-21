/* test_fft.c */
#include <stdio.h>
#include <math.h>
#include "../fft.h"

#define N 8
int main(void)
{
    /* 예제: 8-sample 사각파(0,1,0,-1,0,1,0,-1) */
    // float input[N] = {0, 1, 0, -1, 0, 1, 0, -1};
    // float input[N] = {1, 1, 1, 1, 1, 1, 1, 1};
    // float input[N] = {1, 0, -1, 0, 1, 0, -1, 0};
    // float input[N] = {0, 0, 0, 0, 1, 0, 0, 0};
    float input[N] = {1, -1, 1, -1, 1, -1, 1, -1};

    /* 출력 버퍼 */
    Complex spec[N];

    /* 실수 입력 FFT 수행 */
    fft_real(input, spec, N);

    /* 결과 출력 */
    printf("k |   Re            Im\n");
    printf("-------------------------------\n");
    for (size_t k = 0; k < N; ++k)
    {
        printf("%zu | % .6f  % .6f\n", k, spec[k].real, spec[k].imag);
    }
    return 0;
}

/*
cd test

gcc -std=c11 -O2 -g ./fft_test.c ../fft.c ../complex.c -lm -o fft_test

./test_fft

*/