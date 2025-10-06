#include "mbed.h"
#include "thermistor/Thermistor.h"
#include <cstdio>


BufferedSerial blueToothSerial(D1,D0,9600);

// USB Serial Debugging
BufferedSerial pcSerial(USBTX, USBRX, 115200);

Thermistor therm;

int main()
{
    //therm.InitializeSensor();

    blueToothSerial.set_format(8, BufferedSerial::None, 1);

    pcSerial.write("Program started. Checking Bluetooth...\n", 37);

    // Send an AT command to check Bluetooth connectivity (optional)
    blueToothSerial.write("AT\r\n", strlen("AT\r\n"));
    ThisThread::sleep_for(500ms);


    

    while(true){
        float temperature = therm.ConvertToTemp();
        // Prepare the temperature data to send
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "Temperature: %.2f C\n", temperature);

        // Send temperature over Bluetooth
        blueToothSerial.write(buffer, strlen(buffer));

         // Debug output for temperature
        pcSerial.write(buffer, strlen(buffer));

        // Wait for a second before the next reading
        ThisThread::sleep_for(1s);


    }
  
}

