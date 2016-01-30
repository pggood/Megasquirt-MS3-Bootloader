#include "sliding_window_average.h"

unsigned int sliding_average_update(sliding_average_ctx_st * const pctx, unsigned int const new_value)
{
    if (pctx->samples_inserted < pctx->num_samples)
    {
        pctx->samples_inserted++;
    }
    else
    {
        pctx->sum_of_samples -= pctx->samples[pctx->current_index];
    }
    pctx->samples[pctx->current_index] = new_value;
    pctx->sum_of_samples += pctx->samples[pctx->current_index];
    pctx->current_index++;
    if (pctx->current_index >= pctx->num_samples)
    {
        pctx->current_index = 0;
    }

    return pctx->sum_of_samples / pctx->samples_inserted;
}

void sliding_average_init(sliding_average_ctx_st * const pctx, unsigned int * const samples, uint8_t const num_samples)
{
    pctx->samples = samples;
    pctx->num_samples = num_samples;
    pctx->current_index = 0;
    pctx->samples_inserted = 0;
    pctx->sum_of_samples = 0;
}

