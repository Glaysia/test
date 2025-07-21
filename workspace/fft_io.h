/* fft_io.h */
#ifndef FFT_IO_H
#define FFT_IO_H

#include <stddef.h>
#include "complex.h"

/* 스펙트럼을 실수·허수 텍스트 파일 두 개로 저장 */
int fft_save_realimag(const Complex *spec,
                      const char   *re_path,
                      const char   *im_path,
                      size_t        n);

#endif /* FFT_IO_H */
