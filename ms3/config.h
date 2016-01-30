#ifndef __CONFIG_H__
#define __CONFIG_H__

#define CLOCK_PERIOD_US 128
#define TICKS_PER_10_SEC (unsigned long)(10000000UL/CLOCK_PERIOD_US)
#define TICKS_PER_SECOND (TICKS_PER_10_SEC/10)

/* This macro won't work when millisecs == 0, and resolution 
 * isn't too good when dealing with only a few millisecs 
 */
#define MILLISECS_TO_TICKS(millisecs) ((unsigned long)TICKS_PER_SECOND/(1000/(millisecs)))

#define MAX_RETARD_ANGLE_DECIDEGREES() -450


#endif /* __CONFIG_H__ */
