#ifndef __UTILS_H__
#define __UTILS_H__

#define BIT_ON(variable, bit) (variable) |= (bit)
#define BIT_OFF(variable, bit) (variable) &= ~(bit)

#define GPIO_ON(port, pin)  *(port) |= (pin)
#define GPIO_OFF(port, pin) *(port) &= ~(pin)


#endif /* __UTILS_H__ */
