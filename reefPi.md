# Reef-Pi Page

- **Current Status: Planning**
  - first parts ordered

1. [Target](#target)
2. [Progress](#progress)
    1. [Planning](#planning)

## Target

- maximum of modularity for future changes and cleanliness

### Capabilities

- camera(s)
  - quick view of aquarium
  - could be used to read the digits of a CO2 sensor like here and here
- I2C or ADC
  - pH-Measurement
  - Temp-Measurement
  - Conductivity Measurement
    - perfectionism, I like my data ^^
  - Air quality
- PWM
  - LED-Light
  - sugar-solution dosing
  - fertilizer dosing
- non-essential
  - AC equipment
  - value logging
    - e.g. values from manual water tests
    - sensor recalibrations
    - etc.

### pH Sensor

- pH Sensor circuit from [robo-tank](https://www.robo-tank.ca/Arduino-Devices/Robo-Tank-Isolated-pH-Circuit-Arduino-PI)
  - 0.01 accuracy
- 50$ no-name probe from local aquarium store
  - accuracy and longevity ?
- I2C and power isolation circuit (pre-made)
  - DFRobot circuit, 150mA max curret draw
- I2C connection, 5V

### Temp-Sensor

- two standard DS18B20 sensors
- supposedly prone to failue
  - 2 for backup purposes
- single pin protocol
- 3.3 / 5V power
- Pi GPIO pin needs 3.3V

### Conductivity Measurement

- Cheap first test: [CQRobot TDS circuit](www.cqrobot.wiki/index.php/TDS_(Total_Dissolved_Solids)_Meter_Sensor_SKU:_CQRSENTDS01)
  - cheap (14$)
  - longevity and accuracy for fresh water ?
  - needs ADC (and Isolation ?)
- [DIY build](DIY_EC_Sensor.md)

### Air Quality

- read display of a third party device with a camera
  - complicated dropped in favor of second method
- I2C sensor:
  - [Adafruit Guide](https://learn.adafruit.com/adafruit-scd30/overview)
  - 3.3 / 5V supply
  - CO2, temperature + humidity

### LED-Lights

- no LED decided on yet:
  - fluval Bluetooth LED
    - nice regulation app with weather effects
    - expensive package, each LED-module has it's own Bluetooth connection and chip
    - if you want two for more ligth it's unnecessarily expensive
  - self build Sera Sunshine system, regulated with Reef-Pi
    - PWM circuit for regulation
    - fast enough for weather effects ?
    - cheaper, because just no additional regulation chip needed (apart from Pi Zero)

### Dosing

- afraid of dosing failures with PDA9685
- will chain Zero's PWM pin to all doser pumps
- run them monodirectionally with a ULN2803A transistor array and GPIO pins
- PID regulation of CO2
  - PID in reef-Pi ?
  - regulation by:
    - CO2 pressure (barometric sensors inside CO2 system and ambient)
    - pH value

## Progress

### Planning

#### Progress 12 May 2022

- Power Supply:
  - 12 VDC from 3 pin power cable
  - Ground connection
  - 5.0 VDC from Variable Buck converter
  - 3.3 VDC from Variable Buck converter
- Interface connectors:
  - Power
    - 4-pin MOLEX
  - I2C
    - shielded USB type A cable (+5.0V, SDA SCL, GND)
    - chained through all devices
    - driven from Py through:
      - a BSS138 level shifter + LTC4311 I2C Extender
      - or a ISO1540 I2C isolator (includes level shift)
  - GPIO:
    - 2xDB9 connectors (GND, 8 GPIO 3.3V pins)
    - 4-8xJST PH 3-pin (+5.0V, GND, Pin)
    - connected through a BSS138 level shifter
    - directly interfaces:
      - DS18B20 temperature sensors
      - Water flow sensor
  - PWM:
    - 2xJST 2-pin (GND, PWM pin)
- Modules:
  - ADC Module 
    - Adafruit ADS1015
    - I2C connection
    - power connection
    - signal connection (4 x JST 3-pin connectors: +5.0V, GND, Analog In)
  - PWM Module
    - Adafruit PCA9685
    - I2C connection
    - power connection
    - 16 JST 2-pin connections for PWM out
  - LED Module
    - JST 2-pin connections (isolated)
    - separate 12V power for direct LED drive
  - pH Module
    - Robotank pH circuit
    - I2C connection
  - Air Quality Module
    - SCD30 sensor board
    - I2C connection
  - CO2 pressure Module
    - 2 x BMP280 sensor boards
    - I2C connection
  - AC Power Relais Module
    - DB9 GPIO connection
    - Power connection
  - Doser Module
    - DB9 GPIO connection
    - power connection
    - 2xPWM connection
    - switch to determine which PWM input is used for each doser
  - EC module
    - power and analog connection to ADC
    - internal isolation, both signal and power
