# Sral's Aquarium and Reef-Pi Project

Overview of Sral's Aquarium and Reef-Pi Build. Includes planning and progress reports.

Current Stage:
   - **Aquarium: build-up**
      - step-by-step
   - **Reef-Pi : planning Done**
      - next step: ordering

1. [Reef2Reef Discussion](#reef2reef-discussion)
2. [Project](#project)
    1. [Aquarium](#aquarium)
    2. [Reef-Pi](#reef-pi)
    3. [Background](#background)
3. [Source Material](#source-material)

# Reef2Reef Discussion

Links to the  [Reef2Reef.com](https://www.reef2reef.com/forums/reef-pi-discussion.1296/) threads:
  - [Build Thread](https://www.reef2reef.com/threads/srals-aquarium-and-reef-pi-build.911434/)
    - status: WIP
  - [DIY EC Sensor](https://www.reef2reef.com/threads/diy-ec-sensor.911282/)
    - status: waiting for input + ordering parts
  - [Stale Build Thread](https://www.reef2reef.com/threads/srals-aquarium-and-reef-pi-build.909622/)
    - status: "closed"
    - Reef2Reef doesn't allow editing, so I can't update the Overview
    - created new Build thread and will update here on GitHub

# Project

## Aquarium
  
  - [Aquarium Page](Aquarium.md)
 
## Reef-Pi

  - [Reef-Pi Page](reefPi.md)

## Background

  - non-native english speaker
    - lack in professional terminology
  - MINT PhD student
    - basic background in electrics, electronics, programming, physics and chemistry
    - enough theoretical understanding
    - lack in practical knowledge
      - e.g. prone to forget isolation and protection on signal lines
    - no Aquarium experience
      - apart from Youtube videos

# Source Material
 - Reef2Reef:
    - Robsworld78 ["How To Install Reef-Pi"](https://www.reef2reef.com/threads/how-to-install-reef-pi.889815/) Thread
    - Robsworld78 ["Flow Meter Addon for Reef-Pi"](https://www.reef2reef.com/threads/flow-meter-addon-for-reef-pi.812932/) Thread
 - Adafruit Guides:
    - General Guides:
      - [Reef-Pi Guides](https://learn.adafruit.com/search?q=reef-pi)
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
      - 
 - GitHub Sources:
    - [Reef-Pi project page](https://reef-pi.github.io/)
 - [Robsworld78 Manuals](https://www.robo-tank.ca/reef-pi_Related_User_Manuals)
 - DIY EC Sensor:
   - [DIY EC Sensor](https://publiclab.org/notes/bhickman/05-09-2016/conductivity-and-temperature-meter)
   - [DIY EC Probe Idea](https://hackaday.io/project/7008-hacking-the-way-to-growing-food/log/24646-three-dollar-ec-ppm-meter-arduino)
   - [CQRobot TDS sensor+probe](http://www.cqrobot.wiki/index.php/TDS_(Total_Dissolved_Solids)_Meter_Sensor_SKU:_CQRSENTDS01)
   - [Circuit Info](https://www.analog.com/media/en/reference-design-documentation/reference-designs/CN0428.pdf)
 - Electronics Guides:
   - [Optocoupling PWM signals](https://www.analogictips.com/selecting-optocoupler-isolate-pwm/)
   - [Optocoupling Push-Pull circuit](https://electronics.stackexchange.com/questions/234520/opto-coupled-pwm-output)
 - Pi Infos
   - [Raspberry Pi Pinout](https://pinout.xyz/pinout/i2c#)
   - [Raspberry Pi PInout](https://www.etechnophiles.com/raspberry-pi-zero-gpio-pinout-specifications-programming-language/)
 - DIY CO2 plant
   - [Yeast CO2 production speed](https://uwaterloo.ca/chem13-news-magazine/april-2015/activities/fermentation-sugars-using-yeast-discovery-experiment)
 - Atlas Instruments Guides:
   - [Changing I2C communication mode](https://www.instructables.com/UART-AND-I2C-MODE-SWITCHING-FOR-ATLAS-SCIENTIFIC-E/)
