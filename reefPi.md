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
