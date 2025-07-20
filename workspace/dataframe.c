// dataframe.c
#include "dataframe.h"
#include <stdlib.h>
#include <math.h>

/* 생성·해제 */
DataFrame* df_create(void)
{
    // TODO: 메모리 할당 및 필드 초기화
    return NULL;
}

void df_destroy(DataFrame *df)
{
    // TODO: 메모리 해제
}

/* 정보 조회 */
size_t df_size(const DataFrame *df)
{
    // TODO
    return 0;
}

float df_start(const DataFrame *df)
{
    // TODO
    return 0.0f;
}

float df_end(const DataFrame *df)
{
    // TODO
    return 0.0f;
}

float df_step(const DataFrame *df)
{
    // TODO
    return 0.0f;
}

/* 샘플 접근 */
float df_get(const DataFrame *df, size_t idx)
{
    // TODO
    return 0.0f;
}

int df_set(DataFrame *df, size_t idx, float value)
{
    // TODO
    return 0;
}

/* 초기화/채우기 */
int df_fill_zeros(DataFrame *df)
{
    // TODO
    return 0;
}

int df_fill_constant(DataFrame *df, float value)
{
    // TODO
    return 0;
}

int df_fill_function(DataFrame *df, float (*func)(float x))
{
    // TODO
    return 0;
}

/* 유틸 */
DataFrame* df_clone(const DataFrame *df)
{
    // TODO
    return NULL;
}
