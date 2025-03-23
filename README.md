# Arduino-Uno-Bluetooth-Car

# Description:

This is a Bluetooth-controlled car based on Arduino UNO. It can be controlled using any smartphone.

# Important Note:

Do not program the Arduino board when it is connected to the Motor Driver. You have a risk of damaging you Arduino as well as your computer if your computer is connected to the Arduino

# Equipment list:

1. Arduino Uno - 1
2. Motor Driver Shield (L293D) - 1
3. HC05 Bluetooth Module - 1
4. Logic Level Converter - 1
5. 18560 mAh Battery - 2
6. 18650 Battery Case - 1
7. Push Button Switch - 1
8. 4 Wheel Car Chassis - 1
9. TT Gear Motor - 4
10. Connecting Wires 
11. Soldering Iron 
12. Arduino Car App 

# Picture:

![Image Alt](https://github.com/botfusion/Arduino-Uno-Bluetooth-Car/blob/6794c1474d2c0675521fa1669cbc279fcc5fd4f1/Top%20view.jpg)  ![Image Alt](https://github.com/botfusion/Arduino-Uno-Bluetooth-Car/blob/6794c1474d2c0675521fa1669cbc279fcc5fd4f1/Front%20View.jpg)

# Explanation:

This is a very simple project with a little twist in the circuit and Bluetooth communication part. We are using an Arduino Uno and a motor driver shield to control the 4 TT gear motors.

Why do we need to use a motor driver?
Even though the motors operate at 5V and the Arduino can provide 5V, current and voltage are two different things. The Arduino cannot provide sufficient current to drive the motors, which is why a motor driver is required.

Power Supply:
We are using two 18560 batteries in series, which gives a total of 7.4V (3.7V + 3.7V). These batteries power all the electronics in the system: the Arduino, motor driver, and Bluetooth sensor.

Communication between Arduino and HC05 Bluetooth sensor:
Now comes the tricky part: Arduino operates on 5V logic, while the HC05 Bluetooth sensor operates on 3.3V logic. If any digital pin is connected directly to the pins of the HC05, it could damage the Bluetooth sensor.

Solution: Logic Level Converter
To solve this problem, we use a logic level converter to safely interface the 5V logic of the Arduino with the 3.3V logic of the HC05 Bluetooth sensor.
