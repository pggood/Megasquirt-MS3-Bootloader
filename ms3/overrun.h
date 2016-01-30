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

#define OVERRUN_START_FUEL_CUT_ON_DELAY_TIMER() do {fc_counter = ram4.fc_delay;} while (0)
#define OVERRUN_START_FUEL_CUT_OFF_DELAY_TIMER() do {fc_counter = ram5.fc_trans_time_ret;} while (0)
#define OVERRUN_STOP_TIMER() do {fc_counter = 0;} while (0)
#define OVERRUN_TIMER_ELAPSED() (fc_counter == 0)
#define OVERRUN_TIMER_REMAINING() fc_counter
#define OVERRUN_START_FUEL_CUT_TRANSITION_ON_TIMER() do {fc_counter = ram5.fc_transition_time;} while (0)
#define OVERRUN_ELAPSED_TRANSITION_TIME() (ram5.fc_transition_time - fc_counter)

#define OVERRUN_IS_OFF()               (fc_phase == fuel_cut_off)
#define OVERRUN_IS_IN_ON_DELAY()       (fc_phase == fuel_cut_on_delay)
#define OVERRUN_IS_TRANSITIONING_ON()  (fc_phase == fuel_cut_transitioning_on)
#define OVERRUN_IS_NOT_YET_ON()        (fc_phase < fuel_cut_on)
#define OVERRUN_IS_ON()                (fc_phase == fuel_cut_on)
#define OVERRUN_IS_QUITTING()          (fc_phase == fuel_cut_on_to_off)
#define OVERRUN_IS_TRANSITIONING_OFF() (fc_phase == fuel_cut_transitioning_off)

#define OVERRUN_SET_TO_OFF() do {fc_phase = fuel_cut_off;} while (0)
#define OVERRUN_SET_TO_ON_DELAY() do {fc_phase = fuel_cut_on_delay;} while (0)
#define OVERRUN_SET_TO_TRANSITIONING_ON() do {fc_phase = fuel_cut_transitioning_on;} while (0)
#define OVERRUN_SET_TO_ON() do {fc_phase = fuel_cut_on;} while (0)
#define OVERRUN_SET_TO_QUITTING() do {fc_phase = fuel_cut_on_to_off;} while (0)
#define OVERRUN_SET_TO_TRANSITIONING_OFF() do {fc_phase = fuel_cut_transitioning_off;} while (0)

#endif /* __OVERRUN_H__ */
