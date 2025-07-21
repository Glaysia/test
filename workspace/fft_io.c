/* fft_io.c  –  save_load 모듈 활용 버전 */
#include "fft_io.h"
#include "save_load.h"   /* df_save_txt */
#include "dataframe.h"   /* df_create, df_set, df_destroy */

/* 스펙트럼을 실수·허수 텍스트 파일 두 개로 저장 */
int fft_save_realimag(const Complex *spec,
                      const char   *re_path,
                      const char   *im_path,
                      size_t        n)
{
    if (!spec || !re_path || !im_path || n != DF_SIZE)
        return -1;

    /* 1) 임시 DataFrame 하나만 만들고 내용을 교체해가며 재사용 */
    DataFrame *df = df_create();
    if (!df) return -1;

    /* 2) 실수부 저장 */
    for (size_t i = 0; i < n; ++i)
        df->data[i] = (float)spec[i].real;

    if (df_save_txt(df, re_path) != 0) {
        df_destroy(df);
        return -2;
    }

    /* 3) 허수부로 덮어쓰고 저장 */
    for (size_t i = 0; i < n; ++i)
        df->data[i] = (float)spec[i].imag;

    if (df_save_txt(df, im_path) != 0) {
        df_destroy(df);
        return -3;
    }

    df_destroy(df);
    return 0;
}
