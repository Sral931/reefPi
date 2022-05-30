# DIY PWM LED Dimmer Page

- **Current Status: Waiting for parts**
  - next: build test circuit

1. [Target](#target)
2. [Progress](#progress)
3. [Sources](#sources)

## Target

- control 6 LED channels with PWM signals
- use low resistance, low capacitance n-channel MOSFETs
- optocouple the PWM signal to protect the logic circuitry from 24V DC
- optocouple using push-pull configuration to preserve steep PWM edges
  - steeper edges mean less power dissipation on the MOSFETs
  - if unsuccesfull, use Schmitt-Trigger to generate a steep signal in the dimmer circuit

## Progress

### Parts

- [Optocoupler IC](http://isocom.com/wp-content/uploads/2017/08/dc93164.pdf)
- [n-channel MOSFET](https://assets.nexperia.com/documents/data-sheet/PSMN022-30PL.pdf)
- [npn transistor PN2222](https://rocelec.widen.net/view/pdf/xjvpikgnni/ONSM-S-A0003589513-1.pdf?t.download=true&u=5oefqw)
- [pnp transistor 2N3906](https://www.onsemi.com/pdf/datasheet/pzt3906-d.pdf)
- Alternatives:
  - [Optocoupler Gate Driver IC](https://www.onsemi.com/pdf/datasheet/fod3182-d.pdf)
  - [npn transistor 2N3904](https://www.onsemi.com/pdf/datasheet/pzt3904-d.pdf)
  - [Adafruit n-channel MOSFET](https://cdn-shop.adafruit.com/datasheets/irlb8721pbf.pdf)

## Sources

- Optocoupling PWM signals
  - [Optocoupling PWM signals](https://www.analogictips.com/selecting-optocoupler-isolate-pwm/)
  - [Optocoupling Push-Pull circuit](https://electronics.stackexchange.com/questions/234520/opto-coupled-pwm-output)
- Push-Pull Amplifier
  - [Push-Pull Amplifier Basics](https://www.youtube.com/watch?v=e_SE4KQjYR8)
  - [MOSFET driver Basics](https://www.youtube.com/watch?v=8swJ_Bnsgl4)
