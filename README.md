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


## Software description

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders.

## Video

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References

1. Write your text here.
2. ...
