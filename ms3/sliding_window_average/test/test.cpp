#include <CppUTest/TestHarness.h>
extern "C"
{
	#include "sliding_window_average.h"
};

#define NUM_SAMPLES 10

TEST_GROUP(sliding_window_average)
{
    sliding_average_ctx_st pctx;
    unsigned int samples[NUM_SAMPLES];

    void setup()
    {
        sliding_average_init(&pctx, samples, NUM_SAMPLES);
    }

    void teardown()
    {
    }
};


TEST(sliding_window_average, average_single_sample)
{
    unsigned int average;

    average = sliding_average_update(&pctx, 1);

    LONGS_EQUAL(1, average);

}

TEST(sliding_window_average, average_two_samples)
{
    unsigned int average;

    (void)sliding_average_update(&pctx, 40);
    average = sliding_average_update(&pctx, 60); 

    LONGS_EQUAL(50, average);

}

TEST(sliding_window_average, average_num_samples)
{
    unsigned int average;
    size_t i;

    for (i = 0; i < NUM_SAMPLES; i++)
    {
        average = sliding_average_update(&pctx, 100);
    }

    LONGS_EQUAL(100, average);

}

TEST(sliding_window_average, average_more_than_num_samples)
{
    unsigned int average;
    size_t i;

    /*  
     * Add in some large value that would skew the result if it was 
     * included in the average.
     */
    (void)sliding_average_update(&pctx, 1000); 
    /*  
     * Now add samples until this value is removed from the average.
     */
    for (i = 1; i <= NUM_SAMPLES; i++)
    {
        unsigned int sample_to_insert = i * 10;

        average = sliding_average_update(&pctx, sample_to_insert);
    }

    LONGS_EQUAL((10+20+30+40+50+60+70+80+90+100)/NUM_SAMPLES, average);

}

