/* fft_pipeline.c */
#include "fft_pipeline.h"
#include "save_load.h"   /* df_load_txt, df_destroy */
#include "dataframe.h"
#include "fft.h"         /* fft_real */
#include "fft_io.h"      /* fft_save_realimag */
#include "complex.h"
#include <stdlib.h>

/* 0 : 성공
 * -1: 입력 로드 실패
 * -2: 메모리 할당 실패
 * -3: FFT 저장 실패
 */
int run_fft_pipeline(const char *in_path,
                     const char *out_re,
                     const char *out_im)
{
    /* 1) 입력 시계열 로드 */
    DataFrame *df = df_load_txt(in_path);
    if (!df) return -1;

    size_t n = df_size(df);

    /* 2) FFT 버퍼 */
    Complex *spec = malloc(n * sizeof(Complex));
    if (!spec) {
        df_destroy(df);
        return -2;
    }

    /* 3) FFT 수행 */
    fft_real(df->data, spec, n);

    /* 4) 결과 저장 */
    int rc = fft_save_realimag(spec, out_re, out_im, n) == 0 ? 0 : -3;

    /* 5) 정리 */
    free(spec);
    df_destroy(df);
    return rc;
}
