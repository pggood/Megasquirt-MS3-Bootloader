#ifndef __FAN_CONTROL_H__
#define __FAN_CONTROL_H__

#include "ms3.h"
#include "utils.h"

#define FAN_CONTROL_COOLANT_TEMPERATURE_IS_HIGH() (outpc.clt >= ram4.fanctl_ontemp)
#define FAN_CONTROL_COOLANT_TEMPERATURE_IS_LOW() (outpc.clt <= ram4.fanctl_offtemp)
/* For AC button, only turn on fan if the user wants the fan on with AC */
#define AC_NEEDS_FAN() ((last_acbutton_state == 1) && (ram4.fan_ctl_settings2 & 0x01))

#define FAN_CONTROL_SETPOINTS_ARE_VALID()  (ram4.fanctl_offtemp < ram4.fanctl_ontemp)



#define SET_FAN_STATUS_ON() BIT_ON(outpc.status6, STATUS6_FAN)
#define SET_FAN_STATUS_OFF() BIT_OFF(outpc.status6, STATUS6_FAN)

#define TURN_FAN_ON() \
                    do { \
                        SSEM0SEI; \
                        GPIO_ON(fanctl_out); \
                        CSEM0CLI; \
                    } while (0)

#define TURN_FAN_OFF() \
                    do { \
                        SSEM0SEI; \
                        GPIO_OFF(fanctl_out); \
                        CSEM0CLI; \
                    } while (0)

#define TURN_FAN_OFF_WITHOUT_DISABLING_INTS() \
                    do { \
                        GPIO_OFF(fanctl_out); \
                    } while (0)

#endif /* __FAN_CONTROL_H__ */
