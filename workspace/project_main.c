#include <math.h>

#include "complex.h"
#include "dataframe.h"
#include "save_load.h"
#include "fft_pipeline.h"

void test_complex(void){
    Complex z1 = complex_make(3.0,  4.0);
    Complex z2 = complex_make(1.0, -2.0);

    Complex sum  = complex_add(z1, z2);
    Complex prod = complex_mul(z1, z2);

    printf("z1 + z2 = ");
    complex_print(sum);

    printf("z1 * z2 = ");
    complex_print(prod);
}


/* sample function: y = 2 * sin(20 * x) */
static float sine20(float x) {
    return 2.0f * sinf(20.0f * x);
}

int test_dataframe(void) {
    /* create and initialize DataFrame */
    DataFrame *df = df_create();
    if (!df) {
        fprintf(stderr, "Error: df_create() failed\n");
        return 1;
    }

    /* fill with sine20 function */
    if (df_fill_function(df, sine20) != 0) {
        fprintf(stderr, "Error: df_fill_function() failed\n");
        df_destroy(df);
        return 1;
    }

    /* print first 5 samples */
    printf("First 5 samples:\n");
    for (size_t i = 0; i < 5 && i < df_size(df); ++i) {
        printf("  df[%2zu] = %f\n", i, df_get(df, i));
    }

    /* print last 5 samples */
    size_t n = df_size(df);
    printf("Last 5 samples:\n");
    for (size_t i = (n >= 5 ? n - 5 : 0); i < n; ++i) {
        printf("  df[%2zu] = %f\n", i, df_get(df, i));
    }

    /* clone and modify clone */
    DataFrame *df2 = df_clone(df);
    if (!df2) {
        fprintf(stderr, "Error: df_clone() failed\n");
        df_destroy(df);
        return 1;
    }

    /* demonstrate that original is unchanged */
    df_set(df2, 0, 123.456f);
    printf("After modifying clone at index 0:\n");
    printf("  original df[0] = %f\n", df_get(df, 0));
    printf("  cloned   df2[0] = %f\n", df_get(df2, 0));

    /* clean up */
    df_destroy(df);
    df_destroy(df2);

}

void test_saveload(void) {
    const char *infile  = "data/data_2sin20t.txt";
    const char *outfile = "data/data_4sin20t.txt";

    // 1. 파일에서 DataFrame 로드
    DataFrame *df = df_load_txt(infile);
    if (!df) {
        fprintf(stderr, "Error: failed to load '%s'\n", infile);
        return;
    }

    // 2. 모든 샘플을 두 배로 증폭
    size_t n = df_size(df);
    for (size_t i = 0; i < n; ++i) {
        float v = df_get(df, i);
        df_set(df, i, v * 2.0f);
    }

    // 3. 결과를 새 파일에 저장
    if (df_save_txt(df, outfile) != 0) {
        fprintf(stderr, "Error: failed to save '%s'\n", outfile);
    } else {
        printf("Saved doubled data to '%s' (%zu samples)\n", outfile, n);
    }

    // 4. 메모리 해제
    df_destroy(df);
}

int test_fft_pipeline(void){
    int ret = run_fft_pipeline(
        "data/data_2sin20t.txt",
        "data/fft_2sin20t_real.txt",
        "data/fft_2sin20t_imag.txt");

    if (ret == 0)
        puts("FFT pipeline finished successfully.");
    else
        printf("FFT pipeline failed (code %d).\n", ret);

    return ret;

}

int main(void)
{
    // test_complex();
    // test_dataframe();
    // test_saveload();
    int result = test_fft_pipeline();

    printf("result : %d", result);


    return 0;
}
