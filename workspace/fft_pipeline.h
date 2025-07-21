/* fft_pipeline.h */
#ifndef FFT_PIPELINE_H
#define FFT_PIPELINE_H

/* 전체 파이프라인: 입력 시계열 → FFT → 두 파일에 저장 */
int run_fft_pipeline(const char *in_path,
                     const char *out_re,
                     const char *out_im);

#endif /* FFT_PIPELINE_H */
