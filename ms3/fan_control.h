#ifndef __FAN_CONTROL_H__
#define __FAN_CONTROL_H__

#define COOLANT_TEMPERATURE_IS_HIGH (outpc.clt >= ram4.fanctl_ontemp)
#define COOLANT_TEMPERATURE_IS_LOW (outpc.clt <= ram4.fanctl_offtemp)
/* For AC button, only turn on fan if the user wants the fan on with AC */
#define AC_NEEDS_FAN ((last_acbutton_state == 1) && ram4.fan_ctl_settings2 & 0x01)

#define FAN_CONTROL_SETPOINTS_ARE_VALID  (ram4.fanctl_offtemp < ram4.fanctl_ontemp)

#define TURN_FAN_OFF() *port_fanctl_out &= ~pin_fanctl_out
#define TURN_FAN_ON() *port_fanctl_out |= pin_fanctl_out



#endif /* __FAN_CONTROL_H__ */
