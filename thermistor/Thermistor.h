#ifndef Thermistor_H
#define Thermistor_H
#include <iostream>

#include "mbed.h"

class Thermistor{
    public:
     void InitializeSensor();
     float ConvertToTemp();

    private:
        float calculateResistance(float adc_value);
        float calculateTemperature(float R_therm);
};

#endif