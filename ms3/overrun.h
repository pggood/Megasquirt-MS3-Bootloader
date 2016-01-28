#ifndef __OVERRUN_H__
#define __OVERRUN_H__

typedef enum fuel_cut_phase_t
{
    fuel_cut_off,
    fuel_cut_timing_in,
    fuel_cut_transitioning_on,
    fuel_cut_on,
    fuel_cut_on_to_off,
    fuel_cut_transitioning_off
} fuel_cut_phase_t;

#define OVERRUN_IS_OFF()               (fc_phase == fuel_cut_off)
#define OVERRUN_IS_TIMING_IN()         (fc_phase == fuel_cut_timing_in)
#define OVERRUN_IS_TRANSITIONING_ON()  (fc_phase == fuel_cut_transitioning_on)
#define OVERRUN_IS_NOT_YET_ON()        (fc_phase < fuel_cut_on)
#define OVERRUN_IS_ON()                (fc_phase == fuel_cut_on)
#define OVERRUN_IS_QUITTING()          (fc_phase == fuel_cut_on_to_off)
#define OVERRUN_IS_TRANSITIONING_OFF() (fc_phase == fuel_cut_transitioning_off)

#define OVERRUN_SET_TO_OFF() do {fc_phase = fuel_cut_off;} while (0);
#define OVERRUN_SET_TO_TIMING_IN() do {fc_phase = fuel_cut_timing_in;} while (0);
#define OVERRUN_SET_TO_TRANSITIONING_ON() do {fc_phase = fuel_cut_transitioning_on;} while (0);
#define OVERRUN_SET_TO_ON() do {fc_phase = fuel_cut_on;} while (0);
#define OVERRUN_SET_TO_QUITTING() do {fc_phase = fuel_cut_on_to_off;} while (0);
#define OVERRUN_SET_TO_TRANSITIONING_OFF() do {fc_phase = fuel_cut_transitioning_off;} while (0);

#endif /* __OVERRUN_H__ */
