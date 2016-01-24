#ifndef __FAN_CONTROL_H__
#define __FAN_CONTROL_H__

#include "ms3.h"

#define COOLANT_TEMPERATURE_IS_HIGH() (outpc.clt >= ram4.fanctl_ontemp)
#define COOLANT_TEMPERATURE_IS_LOW() (outpc.clt <= ram4.fanctl_offtemp)
/* For AC button, only turn on fan if the user wants the fan on with AC */
#define AC_NEEDS_FAN() ((last_acbutton_state == 1) && ram4.fan_ctl_settings2 & 0x01)

#define FAN_CONTROL_SETPOINTS_ARE_VALID()  (ram4.fanctl_offtemp < ram4.fanctl_ontemp)

#define GPIO_ON(port, pin)  *(port) |= (pin)
#define GPIO_OFF(port, pin) *(port) &= ~(pin)

#define BIT_ON(variable, bit) (variable) |= (bit)
#define BIT_OFF(variable, bit) (variable) &= ~(bit)

#define SET_FAN_STATUS_ON() BIT_ON(outpc.status6, STATUS6_FAN)
#define SET_FAN_STATUS_OFF() BIT_OFF(outpc.status6, STATUS6_FAN)

#define TURN_FAN_OFF() \
                    do { \
                        SSEM0SEI; \
                        GPIO_OFF(port_fanctl_out, pin_fanctl_out); \
                        CSEM0CLI; \
                    } while (0)

#define TURN_FAN_OFF_UPDATE_STATUS() \
                    do { \
                        TURN_FAN_OFF();
                        SET_FAN_STATUS_OFF();
                    } while (0)

#define TURN_FAN_OFF_WITHOUT_DISABLING_INTS() \
                    do { \
                        GPIO_OFF(port_fanctl_out, pin_fanctl_out); \
                    } while (0)

#define TURN_FAN_ON() \
                    do { \
                        SSEM0SEI; \
                        GPIO_ON(port_fanctl_out, pin_fanctl_out); \
                        CSEM0CLI; \
                    } while (0)


#define TURN_FAN_ON_UPDATE_STATUS() \
                    do { \
                        TURN_FAN_ON();
                        SET_FAN_STATUS_ON();
                    } while (0)

#endif /* __FAN_CONTROL_H__ */
