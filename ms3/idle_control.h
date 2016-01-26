#ifndef __IDLE_CONTROL_H__
#define __IDLE_CONTROL_H__

#include "ms3.h"
#include "utils.h"

#define IDLE_CONTROL_COOLANT_TEMPERATURE_IS_HIGH() (outpc.clt > ram4.FastIdle)
#define IDLE_CONTROL_COOLANT_TEMPERATURE_IS_LOW() (outpc.clt < (ram4.FastIdle - ram4.IdleHyst))


#define TURN_FAST_IDLE_OFF() \
                    do { \
                        SSEM0SEI; \
                        GPIO_OFF(port_idleonoff, pin_idleonoff); \
                        CSEM0CLI; \
                    } while (0)

#define TURN_FAST_IDLE_ON() \
                    do { \
                        SSEM0SEI; \
                        GPIO_ON(port_idleonoff, pin_idleonoff); \
                        CSEM0CLI; \
                    } while (0)


#endif /* __IDLE_CONTROL_H__ */
