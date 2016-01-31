#ifndef __OVERRUN_H__
#define __OVERRUN_H__

typedef enum fuel_cut_phase_t
{
    fuel_cut_off,
    fuel_cut_on_delay,
    fuel_cut_transitioning_on,
    fuel_cut_on,
    fuel_cut_on_to_off,
    fuel_cut_transitioning_off
} fuel_cut_phase_t;

#define OVERRUN_START_FUEL_CUT_ON_DELAY_TIMER() do {fuel_cut_counter = ram4.fuel_cut_delay;} while (0)
#define OVERRUN_START_FUEL_CUT_OFF_DELAY_TIMER() do {fuel_cut_counter = ram5.fuel_cut_trans_time_ret;} while (0)
#define OVERRUN_STOP_TIMER() do {fuel_cut_counter = 0;} while (0)
#define OVERRUN_TIMER_ELAPSED() (fuel_cut_counter == 0)
#define OVERRUN_TIMER_REMAINING() fuel_cut_counter
#define OVERRUN_START_FUEL_CUT_TRANSITION_ON_TIMER() do {fuel_cut_counter = ram5.fuel_cut_transition_time;} while (0)
#define OVERRUN_ELAPSED_TRANSITION_TIME() (ram5.fuel_cut_transition_time - fuel_cut_counter)

#define OVERRUN_IS_OFF()               (fuel_cut_phase == fuel_cut_off)
#define OVERRUN_IS_IN_ON_DELAY()       (fuel_cut_phase == fuel_cut_on_delay)
#define OVERRUN_IS_TRANSITIONING_ON()  (fuel_cut_phase == fuel_cut_transitioning_on)
#define OVERRUN_IS_NOT_YET_ON()        (fuel_cut_phase < fuel_cut_on)
#define OVERRUN_IS_ON()                (fuel_cut_phase == fuel_cut_on)
#define OVERRUN_IS_QUITTING()          (fuel_cut_phase == fuel_cut_on_to_off)
#define OVERRUN_IS_TRANSITIONING_OFF() (fuel_cut_phase == fuel_cut_transitioning_off)

#define OVERRUN_SET_TO_OFF() do {fuel_cut_phase = fuel_cut_off;} while (0)
#define OVERRUN_SET_TO_ON_DELAY() do {fuel_cut_phase = fuel_cut_on_delay;} while (0)
#define OVERRUN_SET_TO_TRANSITIONING_ON() do {fuel_cut_phase = fuel_cut_transitioning_on;} while (0)
#define OVERRUN_SET_TO_ON() do {fuel_cut_phase = fuel_cut_on;} while (0)
#define OVERRUN_SET_TO_QUITTING() do {fuel_cut_phase = fuel_cut_on_to_off;} while (0)
#define OVERRUN_SET_TO_TRANSITIONING_OFF() do {fuel_cut_phase = fuel_cut_transitioning_off;} while (0)

#endif /* __OVERRUN_H__ */
