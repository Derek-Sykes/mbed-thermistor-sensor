#include "mbed.h"
#include "Thermistor.h"

AnalogIn pin_thermistor(A0);



void Thermistor::InitializeSensor(){
    printf("Sensor initialized\n");
}

float Thermistor::calculateResistance(float adc_value) {
    const float R_b = 100000.0;  
    const float ADC_ = 65535.0; 
    float R_therm = R_b * ((ADC_ / adc_value) - 1.0);
    return R_therm;
}

float Thermistor::calculateTemperature(float R_therm) {
    const float R_0 = 100000.0;  
    const float Beta = 4250.0;   
    const float T_0 = 298.15;   
    float temp_K = 1.0 / (log(R_therm / R_0) / Beta + (1.0 / T_0));
    float temp_C = temp_K-273.15;
    return temp_C;
}

float Thermistor::ConvertToTemp() {
    float r_therm = 0.0;
    float adc_value = 0.0;
    float temperature;
    adc_value = pin_thermistor.read_u16();
    r_therm = calculateResistance(adc_value);
    temperature = calculateTemperature(r_therm);
    return temperature;
}

