#ifndef __AC_CONTROL_H__
#define __AC_CONTROL_H__

#include "ms3.h"
#include "utils.h"

#define AC_CONTROL_RPM_TOO_LOW() (outpc.rpm < ram4.ac_idleup_min_rpm)

#define SET_AC_STATUS_ON() BIT_ON(outpc.status7, STATUS7_ACOUT)
#define SET_AC_STATUS_OFF() BIT_OFF(outpc.status7, STATUS7_ACOUT)

#define TURN_AC_OFF() \
                    do { \
                        SSEM0SEI; \
                        GPIO_OFF(ac_out); \
                        CSEM0CLI; \
                    } while (0)

#define TURN_AC_ON() \
                    do { \
                        SSEM0SEI; \
                        GPIO_ON(ac_out); \
                        CSEM0CLI; \
                    } while (0)

#define TURN_AC_ON_UPDATE_STATUS() \
                    do { \
                        TURN_AC_ON(); \
                        SET_AC_STATUS_ON(); \
                    } while (0)

#define TURN_AC_OFF_UPDATE_STATUS() \
                    do { \
                        TURN_AC_OFF(); \
                        SET_AC_STATUS_OFF(); \
                    } while (0)


#endif /* __AC_CONTROL_H__ */
