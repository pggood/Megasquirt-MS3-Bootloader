#ifndef __SLIDING_WINDOW_AVERAGE_H__
#define __SLIDING_WINDOW_AVERAGE_H__

#include <stddef.h>

typedef struct sliding_average_ctx_st sliding_average_ctx_st;
struct sliding_average_ctx_st
{
    unsigned int * samples;
    size_t num_samples;
    size_t samples_inserted;
    size_t current_index;
    unsigned int sum_of_samples;
};


unsigned int sliding_average_update(sliding_average_ctx_st * const pctx, unsigned int const new_value);
void sliding_average_init(sliding_average_ctx_st * const pctx, unsigned int * const samples, size_t const num_samples);


#endif /* __SLIDING_WINDOW_AVERAGE_H__ */
