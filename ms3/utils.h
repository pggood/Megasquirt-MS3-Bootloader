#ifndef __UTILS_H__
#define __UTILS_H__

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

#define BIT_ON(variable, bit) (variable) |= (bit)
#define BIT_OFF(variable, bit) (variable) &= ~(bit)

#define GPIO_ON(port, pin)  *(port) |= (pin)
#define GPIO_OFF(port, pin) *(port) &= ~(pin)

#define BIT(x) (twopow[x])

#define LIMIT(val, min, max) \
            do {if ((val) < (min)) val = min; else if ((val) > (max)) (val) = (max);} while (0);

#define GPIO_ACTIVE(gpio) \
            (pin_ ## gpio  && ((*port_ ## gpio & pin_ ## gpio) == pin_match_ ## gpio))

/* Converts from a percentage into some other scale. Doesn't 
 * do any rounding.
 */
#define PERCENT_TO_OTHER_SCALE(percentage, other_scale) ((((unsigned int)(percentage) * (other_scale))) / 100)


#endif /* __UTILS_H__ */
