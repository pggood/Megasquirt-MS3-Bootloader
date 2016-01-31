#ifndef __UTILS_H__
#define __UTILS_H__

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

#define BIT_ON(variable, bit) (variable) |= (bit)
#define BIT_OFF(variable, bit) (variable) &= ~(bit)

#define GPIO_ON(port, pin)  *(port) |= (pin)
#define GPIO_OFF(port, pin) *(port) &= ~(pin)

#define BIT(x) (twopow[x])

#endif /* __UTILS_H__ */
