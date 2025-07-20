// save_load.c
#include "save_load.h"
#include <stdio.h>
#include <stdlib.h>

/* Text 형식 저장 */
int df_save_txt(const DataFrame *df, const char *filename)
{
    // TODO: fopen, fprintf 메타데이터, for-loop fprintf data[], fclose
    return 0;
}

/* Text 형식 로드 */
DataFrame* df_load_txt(const char *filename)
{
    // TODO: fopen, fscanf 메타데이터, df_create + for-loop fscanf data[], fclose
    return NULL;
}
