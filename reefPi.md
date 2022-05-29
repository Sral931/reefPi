# Reef-Pi Page

- **Current Status: Planning**
  - first parts ordered

1. [Target](#target)
2. [Planning](#planning)
    1. [Progress 12 May 2022](#progress-12-may-2022)
3. [Progress](#progress)
4. [Sources](#sources)

## Target

- maximum of modularity for future changes and cleanliness

### Capabilities

- camera(s)
  - quick view of aquarium
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
  - accuracy and longevity to be determined

### Temp-Sensor

- two standard DS18B20 sensors
  - prone to brakdowns ? -> backup

### Conductivity Measurement

- Cheap first test: [CQRobot TDS circuit](www.cqrobot.wiki/index.php/TDS_(Total_Dissolved_Solids)_Meter_Sensor_SKU:_CQRSENTDS01)
  - cheap (14$)
  - longevity and accuracy for fresh water ?
  - needs ADC (and Isolation?)
- [DIY build](diyec.md)

### Air Quality

- read display of a third party device with a camera
  - complicated, dropped in favor of second method
- I2C sensor:
  - [Adafruit Guide](https://learn.adafruit.com/adafruit-scd30/overview)
  - 3.3 / 5V supply
  - CO2, temperature + humidity

### LED-Lights

- [Aqua Grow Solid LS 870](https://aqua-grow.de/lampen/solid-ls/68/solid-ls-870?c=19)
  - power: 92W
  - Lumen: ~10,000 lm
  - color: ~6300K
  - supply: DC 24V @LED
- [DIY PWM Dimmer](diyPWMDimmer.md)
  - optocoupled PWM signal from PDA9685
  - Pulse width modulated output through 6 n-channel MOSFETs  

### Dosing

- afraid of dosing failures with PDA9685
- will chain Zero's PWM pin to all doser pumps
- run them monodirectionally with a ULN2803A transistor array (or similar) and GPIO pins
- PID regulation of CO2
  - PID in reef-Pi ?
  - regulation by:
    - pH value
    - CO2 pressure (barometric sensors inside CO2 system and ambient ?)
    - ambient temperature (?)
    - manually determined max as safety

## Planning

### [Progress 12 May 2022](https://www.reef2reef.com/threads/srals-aquarium-and-reef-pi-build.911434/post-10209141)

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

## Sources
- [Reef-Pi project page](https://reef-pi.github.io/)
- Reef-Pi Guides:
  - General Guides:
    - Robsworld78 ["How To Install Reef-Pi"](https://www.reef2reef.com/threads/how-to-install-reef-pi.889815/) Thread
    - [Robsworld78 Reef-Pi Manual](https://www.robo-tank.ca/reef-pi_Related_User_Manuals)
  - Reef-Pi Circuits:
    - [Reef-Pi Guides on Adafruit](https://learn.adafruit.com/search?q=reef-pi)
    - Robsworld78 ["Flow Meter Addon for Reef-Pi"](https://www.reef2reef.com/threads/flow-meter-addon-for-reef-pi.812932/) Thread
- General Circuits:      
  - I2C Architecture circuits
    - [LTC4311 I2C Extender](https://learn.adafruit.com/adafruit-ltc4311-i2c-extender-active-terminator)
    - [BSS138 level shifter (shop page)](https://www.adafruit.com/product/757)
    - [DFRobot I2C Signal+Power Isolator](https://wiki.dfrobot.com/Gravity__Digital_Signal_Isolator_SKU__DFR0565)
  - I2C Sensor/Actuator Circuits:
    - [ADS1015/1115 I2C 4-channel ADC](https://learn.adafruit.com/adafruit-4-channel-adc-breakouts)
    - [BMP280 I2C Pressure sensor](https://learn.adafruit.com/adafruit-bmp280-barometric-pressure-plus-temperature-sensor-breakout)
    - [PDA9685 I2C 16-channel PWM circuit](https://learn.adafruit.com/16-channel-pwm-servo-driver)
    - [SCD30 I2C CO2 sensor](https://learn.adafruit.com/adafruit-scd30/overview)
  - Real Time Clock (RTC)
    - [DS1307 I2C RTC module](https://learn.adafruit.com/adding-a-real-time-clock-to-raspberry-pi)
- Atlas Instruments Guides:
   - [Changing I2C communication mode](https://www.instructables.com/UART-AND-I2C-MODE-SWITCHING-FOR-ATLAS-SCIENTIFIC-E/)
