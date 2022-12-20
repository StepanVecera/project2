# Project 2

Precise generation of several PWM channels. Application of two (or more) Servo motors SG90.

## Instructions

The goal of the project is cooperation in pairs, further study of the topic, design of own solutions, implementation, creation of project documentation and presentation of results. The division of roles and tasks within the team is up to their members.

* Students work on a project in the labs during the 12th and 13th weeks of the semester.

* Through the BUT e-learning, students submit a link to the GitHub repository, which contains the complete project in PlatfomIO and a descriptive README file. The submission deadline is the day before the next laboratory, i.e. in 2 weeks.

* The source code for the AVR must be written in C and/or Assembly and must be implementable on Arduino Uno board using toolchains from the semester, ie PlatformIO and not in the Arduino-style. No other development tools are allowed.

### Team members

* Šimon Buchta (coding, flowcharts, wireing)
* Štěpán Večeřa (coding, readme)

## Hardware description

**Servo motor SG90**

Servo motor is an special kind of dc motor, whitch can hold position thanks to its feedback mechanism. This feedback device supplies information such as current, velocity and position to the servo controller. Position of servo is determined by pulse width supplied by arduino. Servo motors are capable of generating serious torque even with small dimensions and weight.

Our servo have three wires. Red to supply voltage (5V), brown to supply ground, and orange one to transmit PWM signal, witch controls position of servo.
Figure below shows how duty cycle coresponds to position of servo.

![arduino pwm](https://user-images.githubusercontent.com/99388270/208290677-11a39c81-5e7f-44db-b1ef-3ce06e0724c8.png)

Figure below shows wirering of our project.

![project2 schema](https://user-images.githubusercontent.com/99388270/208300571-05e2b2ab-930d-46a2-b837-ed821195ad10.jpg)


**joystick**

Joystick is an input device. It consists of two potentiometers and a push button. The potentiometers indicate in whitch direction is the joystick being pushed. this device has five pins. three of whitch are inputs to Arduino, while the remaining two supply voltage (5 V) and ground. The graphic below shows the X and Y directions and also gives an indication of how the outputs will respond when the joystick is pushed in various directions. In our project, we use only X axis to control position of servo.

![joystick](https://user-images.githubusercontent.com/99388270/205435527-94b1b353-9a05-48d7-9741-ecba4a571a7a.png)

## Software description

**FLOWCHARTS:**

**Timer1_ovf_vect**
![DE2-PROJEKT 2 TIMER1](https://user-images.githubusercontent.com/99410540/208731839-5f05e4d6-39d0-4a8c-a182-f27629beb2ed.png)

**ADC_vect**
![DE2-PROJEKT2 ADC](https://user-images.githubusercontent.com/99410540/208731870-d911b12d-7058-4bc0-8466-c71b6a3ef081.png)


**timer.h**

This library is used in our project to set prescalers for clock signal and to enable interrupt caused by ovrflowing of timer.
You can see our library [here](https://github.com/StepanVecera/project2/blob/main/include/timer.h).


**gpio.h**

This library is for declaring  functions whitch are defined in [gpio.c](https://github.com/StepanVecera/project2/blob/main/lib/gpio/gpio.c). We use this library to set pins as inputs and to read their value (1/0). 


Part of this readme was taken from [previos project](https://github.com/StepanVecera/projekt1)

## Video

https://youtu.be/sD7s3yCammY

## References
1. [Arduino pinout](https://docs.arduino.cc/static/6ec5e4c2a6c0e9e46389d4f6dc924073/2f891/Pinout-UNOrev3_latest.png)
2. [ATmega 328 Datasheet](https://www.microchip.com/en-us/product/ATmega328p)
3. [Joystick](https://components101.com/sites/default/files/component_datasheet/Joystick%20Module.pdf)
4. [servo motor basics](https://howtomechatronics.com/how-it-works/how-servo-motors-work-how-to-control-servos-using-arduino/)
5. [servo motor SG90 data sheet](http://www.ee.ic.ac.uk/pcheung/teaching/DE1_EE/stores/sg90_datasheet.pdf)
6. [servo motor with arduino](https://www.teachmemicro.com/arduino-servo-motor-tutorial/)
7. [github of Tomas Fryza](https://github.com/tomas-fryza/digital-electronics-2)
