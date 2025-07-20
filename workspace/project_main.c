#include <math.h>

#include "complex.h"
#include "dataframe.h"

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


int main(void) {
    // test_complex();
    test_dataframe();

    return 0;
}
