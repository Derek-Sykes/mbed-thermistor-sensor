# Mbed Bluetooth Temperature Sensor 🌡️

This project is the **Embedded Part** of the *Mandatory Embedded-Mobile Exercise (AME2425)* for the **Embedded and Mobile Applications** course at *Universitat Rovira i Virgili (URV)*.

It measures ambient temperature using a **thermistor**, converts the analog readings into Celsius, and sends them via **Bluetooth Serial (SPP)** to a computer or mobile device. The transmitted data can be viewed in real time through **PuTTY**, a serial terminal, or a mobile app connected via Bluetooth.

---

## 🔧 Features
- Reads temperature using an **NTC thermistor**
- Converts analog voltage to temperature (Celsius)
- Communicates data over **Bluetooth (HC-05/HC-06)**
- Built with **Mbed OS 6**
- Outputs temperature readings every few seconds via **Serial Bluetooth profile**

---

## 🧰 Hardware Requirements
| Component | Description |
|------------|-------------|
| **Mbed-compatible MCU** | e.g., NUCLEO-F401RE, LPC1768, etc. |
| **NTC Thermistor** | Used for temperature sensing |
| **Resistor** | For voltage divider circuit |
| **Bluetooth Module** | HC-05 or HC-06 (Serial Profile) |
| **USB Cable** | For flashing and serial monitoring |
| **Breadboard & Jumpers** | For wiring connections |

---

## ⚙️ Circuit Diagram
**Voltage Divider Setup**
```
(VCC) ---- [R_fixed] ----(Analog In)---- [Thermistor] ---- (GND)
```
- The midpoint (between R_fixed and the thermistor) is connected to an analog input pin (e.g., `A0`).
- The Bluetooth TX and RX pins connect to the MCU’s serial interface (e.g., `D1` and `D0`).

---

## 🧠 Software Setup
1. Open the project in **Mbed Studio**.
2. Select your target board.
3. Connect the **Bluetooth module** (HC-05/HC-06) to serial pins.
4. Build and flash the program.
5. Pair your Bluetooth module with your computer or phone.
6. Open **PuTTY** or another serial terminal:
   - **Baud rate:** 9600  
   - **Port:** COM port of your Bluetooth device  
   - You’ll see temperature readings every few seconds.

---

## 🧮 Temperature Calculation
The thermistor’s resistance is derived from the ADC value:
```
R_thermistor = R_fixed * (1 / (Vout/Vin) - 1)
```
Then the **Steinhart–Hart equation** (or simplified Beta formula) is used to compute temperature:
```
1/T = 1/T₀ + (1/β) * ln(R/R₀)
```
where:
- **T** = temperature in Kelvin  
- **β** = Beta coefficient of thermistor  
- **R₀** = resistance at reference temperature (T₀ = 25°C)  

Convert to Celsius:
```
T(°C) = T(K) - 273.15
```

---

## 🧪 Example Serial Output
```
Connected to Bluetooth device...
Temperature: 23.8 °C
Temperature: 24.0 °C
Temperature: 24.2 °C
```

---

## 🧩 Testing
- Verified voltage readings using a multimeter.
- Tested Bluetooth transmission via **PuTTY** and **Serial Bluetooth Terminal (Android)**.
- Ensured stable serial communication and accurate readings.
- Calibrated results against known room temperatures (±0.5°C accuracy).

---

## 📦 Repository Structure
```
mbed-bluetooth-temperature-sensor/
├── main.cpp
├── mbed-os/                # Mbed OS dependency (ignored via .gitignore)
├── mbed_app.json
├── .mbed
├── .gitignore
└── README.md
```

---

## 📜 License
Released under the [MIT License](LICENSE).

---

## 👤 Author
**Derek Sykes**  
Embedded and Mobile Applications — *Universitat Rovira i Virgili (AME2425)*  
GitHub: [https://github.com/Derek-Sykes](https://github.com/Derek-Sykes)

---

> *“Measure, connect, and communicate — a bridge between the physical and digital worlds.”*
