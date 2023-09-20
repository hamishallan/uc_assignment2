// a1839619
// Driver functions

#include "reg167.h"
#include "driver.h"
#include "pindefs.h"

///**
//    \fn         void setSFR(volatile unsigned int *reg, unsigned int value);
//    \brief      Set the value of a specific SFR (Special Function Register)
//    \param[in]  reg   Pointer to the SFR
//    \param[in]  value Value to be set to the SFR
//*/
//static void setSFR(volatile unsigned int *reg, unsigned int value) {
//	*reg = value;
//}

///**
//    \fn         unsigned int readPin(volatile unsigned int *reg, unsigned int pin);
//    \brief      Read the value of a specific pin
//    \param[in]  reg   Pointer to the register controlling the pin
//    \param[in]  pin   Pin number
//    \return     Value of the pin (0 or 1)
//*/
//static unsigned int readPin(volatile unsigned int *reg, unsigned int pin) {
//	return (*reg & (1U << (pin))) ? 1 : 0;
//}

void setPin(volatile unsigned int *reg, unsigned int pin, unsigned int value) {
    if (value == 1U) {
        // Set the pin to 1 by OR-ing with a mask
        *reg |= (1U << (pin));
    } else {
        // Set the pin to 0 by AND-ing with the inverse of the mask
        *reg &= ~(1U << pin);
    }
}
