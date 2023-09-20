// a1839619

#ifndef DRIVER_H
#define DRIVER_H

/**
    \fn         void setPin(volatile unsigned int *reg, unsigned int pin, unsigned int value);
    \brief      Set the value of a specific pin
    \param[in]  reg   Pointer to the register controlling the pin
    \param[in]  pin   Pin number
    \param[in]  value Value to be set to the pin (0 or 1)
*/
void setPin(volatile unsigned int *reg, unsigned int pin, unsigned int value);


#endif