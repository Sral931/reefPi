# Reef-Pi Page

- **Current Status: Planning**
  - first parts ordered

1. [Target](#target)
2. [Planning](#planning)
    1. [Interfaces](#interfaces)
    2. [Power Supply](#power-supply)
    3. [RTC](#rtc)
    4. [pH Sensor](#ph-sensor)
    5. [ADC Module](#adc-module)
    6. [Temp-Sensor](#temp-sensor)
    7. [Conductivity Measurement](#conductivity-measurement)
    8. [Air Quality](#air-quality)
    9. [Air and CO2 pressure](#air-and-co2-pressure)
    10. [LED-Lights](#led-lights)
    11. [Dosing](#dosing)
3. [Circuits](#circuits)
    1. [Power Supply](#power-supply-circuit)
5. [Progress](#progress)
    1. [Progress 12 May 2022](#progress-12-may-2022)
    2. []
6. [Sources](#sources)

## Target

- maximum of modularity for future changes and cleanliness

### Capabilities

- Real time clock (RTC)
- camera(s)
- pH-Measurement
- Temp-Measurement
- Conductivity Measurement
- Air quality
- PWM-out
  - LED-Lighting
  - sugar-solution dosing
  - fertilizer dosing
- switching AC equipment
- value logging

## Planning

### Interfaces
  - Power
    - 4-pin MOLEX (12VDC + 5VDC)
  - I2C
    - shielded USB type A cable (+5.0V, SDA SCL, GND)
    - ISO1540 I2C isolator (includes level shift from 3.3V to 5V)
    - LTC4311 I2C Extender (boosts I2C for long cables)
  - GPIO:
    - DB9 connectors (GND, 8 GPIO 5.0V pins)
      - driven by ULN2803
    - 4-8xJST PH 3-pin (+5.0V, GND, Pin)
      - connected through a BSS138 level shifter
    - directly interfaces:
      - DS18B20 temperature sensors
      - Water flow sensor
  - PWM:
    - 2xJST 2-pin (GND, PWM pin)
    - more from PWM Lighting Module if needed

### power supply

- [detailed power draw list](https://www.reef2reef.com/threads/srals-aquarium-and-reef-pi-build.911434/post-10340856)
- 12V 3.0A 36W power supply
  - [source](https://www.robo-tank.ca/Bargain-Bin/12V-DC-3.2A-36W-Switching-Power-Supply)
  - power draw:
    - 5V converters: 235-680 mA @ 12V (85% efficiency)
    - peristaltic dosers: 0-1200 mA @ 12V (200-300mA per pump)
    - Total: 235-1880 mA @ 12V
    - Draw on AC: 3.32-26.55 W @ 240 VAC (85% efficiency)
- 2x 5V 3.0A DC/DC step down converter (max 2.0A continuous without heatsink)
  - [datasheet](https://media.digikey.com/pdf/Data%20Sheets/DFRobot%20PDFs/DFR0379_Web.pdf)
  - power draw:
    - Main Pi unit: 450-550 mA @ 5V
    - AC+LED unit: 30-830 mA @ 5V

### RTC
- Adafruit PCF8523
- [Adafruit Guide](https://learn.adafruit.com/adafruit-pcf8523-real-time-clock/)
- back up time keeping
- I2C 7-bit address 0x68 / #104

### pH Sensor

- pH Sensor circuit from [robo-tank](https://www.robo-tank.ca/Arduino-Devices/Robo-Tank-Isolated-pH-Circuit-Arduino-PI)
  - 0.01 accuracy
  - power consumption unknown (10mA max ?)
- 50$ no-name probe from local aquarium store
  - accuracy and longevity to be determined
- I2C 7-bit address 0x62 / #98

### ADC module
- Adafruit ADS1115
- I2C 7-bit address:
  - 0x48 / #72 (1001000) ADR -> GND
  - 0x49 / #73 (1001001) ADR -> VDD
  - 0x4A / #74 (1001010) ADR -> SDA
  - 0x4B / #75 (1001011) ADR -> SCL

### Temp-Sensor

- two standard DS18B20 sensors
  - prone to brakdowns ? -> backup
  - low power consumption (~1mA)

### Conductivity Measurement

- Cheap first test: [CQRobot TDS circuit](http://www.cqrobot.wiki/index.php/TDS_(Total_Dissolved_Solids)_Meter_Sensor_SKU:_CQRSENTDS01)
  - cheap (14$)
  - longevity and accuracy for fresh water ?
  - needs ADC (and Isolation?)
  - power consumption 3-6mA
- [DIY build](diyec.md)
  -  power consumption ?

### Air Quality

- read display of a third party device with a camera
  - complicated, dropped in favor of second method
- I2C sensor: 
  - [SCD30 datasheet](https://media.digikey.com/pdf/Data%20Sheets/Sensirion%20PDFs/CD_DS_SCD30_Datasheet_D1.pdf)
  - [Adafruit Guide](https://learn.adafruit.com/adafruit-scd30/overview)
  - [Interface description](https://sensirion.com/media/documents/D7CEEF4A/6165372F/Sensirion_CO2_Sensors_SCD30_Interface_Description.pdf)
  - 3.3 / 5V supply
  - power consumption 19mA @ 1 measurement per 2s
  - CO2, temperature + humidity
- I2C 7-bit address 0x61 / #97

### Air and CO2 pressure

- read air and CO2 pressure and temperature
- uses 2xBMP280 sensors
- [datasheet](https://media.digikey.com/pdf/Data%20Sheets/Pimoroni%20PDFs/PIM411_Web.pdf)
- I2C 7-bit addresses:
  - 0x76 / #118
  - 0x77 / #119
- low power consumption (<1mA)

### LED-Lights

- [Aqua Grow Solid LS 870](https://aqua-grow.de/lampen/solid-ls/68/solid-ls-870?c=19)
  - power: 92W
  - Lumen: ~10,000 lm
  - color: ~6300K
  - supply: DC 24V @LED
- [DIY PWM Dimmer](diyPWMDimmer.md)
  - PWM signal from PDA9685
    - [datasheet](https://cdn-shop.adafruit.com/datasheets/PCA9685.pdf)
    - [guide](https://learn.adafruit.com/16-channel-pwm-servo-driver?view=all)
    - I2C 7-bit addresses:
      - #64 ... #95
      - 0x40 / #64 (no jumpers)
      - 0x41 / #65 (A0 bridged)
      - 0x42 / #66 (A1 bridged)
      - 0x43 / #67 (A0+A1 bridged)
      - 0x44 / #68 (A2 bridged)
      - 0x45 / #69 (A2+A0 bridged)
      - 0x46 / #70 (A2+A1 bridged)
      - ...
  - optocoupled gate driver FOD3182
    - [datasheet](https://www.onsemi.com/pdf/datasheet/fod3182-d.pdf)
  - Pulse width modulated output through 6 n-channel MOSFETs
  - power consumption ~6 x 10mA

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

## Circuits

### Power Supply Circuit



## Progress

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
