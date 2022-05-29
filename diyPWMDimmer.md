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

- here be success

## Sources

- Optocoupling PWM signals
  - [Optocoupling PWM signals](https://www.analogictips.com/selecting-optocoupler-isolate-pwm/)
  - [Optocoupling Push-Pull circuit](https://electronics.stackexchange.com/questions/234520/opto-coupled-pwm-output)
