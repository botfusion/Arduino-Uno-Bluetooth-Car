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

![Image Alt](https://github.com/botfusion/Arduino-Uno-Bluetooth-Car/blob/b26562bf89d7ebbb3bf4a2e48c6a4e0ab946f851/img/Front%20View.jpg)  ![Image Alt](https://github.com/botfusion/Arduino-Uno-Bluetooth-Car/blob/b26562bf89d7ebbb3bf4a2e48c6a4e0ab946f851/img/Top%20view.jpg)

# Explanation:

This is a very simple project with a little twist in the circuit and Bluetooth communication part. We are using an Arduino Uno and a motor driver shield to control the 4 TT gear motors.

Why do we need to use a motor driver?
Even though the motors operate at 5V and the Arduino can provide 5V, current and voltage are two different things. The Arduino cannot provide sufficient current to drive the motors, which is why a motor driver is required.

Power Supply:
We are using two 18560 batteries in series, which gives a total of 7.4V (3.7V + 3.7V). These batteries power all the electronics in the system: the Arduino, motor driver, and Bluetooth sensor.

Communication between Arduino and HC05 Bluetooth sensor:
Now comes the tricky part, Arduino operates on 5V logic, while the HC05 Bluetooth sensor operates on 3.3V logic. If any digital pin is connected directly to the pins of the HC05, it could damage the Bluetooth sensor.

Solution: Logic Level Converter
To solve this problem, we use a logic level converter to safely interface the 5V logic of the Arduino with the 3.3V logic of the HC05 Bluetooth sensor.

# Circuit Diagram:

![Image Alt](https://github.com/botfusion/Arduino-Uno-Bluetooth-Car/blob/895c062cc8882d053cbc1f99b476a7561c3cdf4c/img/circuit%20diagram.png)

# Project Overview

This is a simple project that involves controlling a set of motors using an Arduino Uno and a Motor Driver Shield. For this project, we will be using hookup wires and modules, so there's no need for a PCB or schematic diagram. However, I have created a circuit diagram using **Fritzing** for reference.

## Motor Connections

There are four motors:

- **FMR (Front Motor Right)**: Connected to Port 4 of the Motor Driver Shield
- **FML (Front Motor Left)**: Connected to Port 1
- **BMR (Back Motor Right)**: Connected to Port 3
- **BML (Back Motor Left)**: Connected to Port 2

As the names suggest, **FMR** stands for **Front Motor Right**, and you can infer the others from this naming convention.

## Power Supply

We use **two 18560 batteries** in series, providing a total of **7.4V** (3.7V + 3.7V). These batteries power the entire system, including:

- Arduino Uno
- Motor Driver Shield
- Bluetooth Module

## Bluetooth Module Connection

To connect the **Bluetooth Module**, follow these steps:

### 1. Soldering Extra Pins to the Motor Driver Shield

- First, solder the **A0-A5 pins** to the Motor Driver Shield. These are clearly labeled on the shield.
- After soldering, these pins will connect directly to the **A0-A5 pins** on the Arduino Uno.

### 2. Soldering 5V, GND, and Vin Pins

- Next, solder the **5V**, **GND**, and **Vin** pins on the Motor Driver Shield. This is done in the same way as the A0-A5 pins.
- Once soldered, these pins will be directly connected to the **5V**, **GND**, and **Vin** pins on the Arduino Uno.

### 3. Soldering the 3.3V Pin

- There is one more soldering step for the **3.3V pin**. By default, this pin on the Arduino coincides with the pin on the Motor Driver Shield.
- **Desolder** the 3.3V pin from the Motor Driver.
- After desoldering, **resolder** a new pin in the same position as the previous pins. This pin will be used for the **orange-colored wire** in the circuit (please refer to the circuit diagram above).

## Circuit Diagram

The detailed circuit diagram for this project can be found in the attached Fritzing file.

---

This should give you an easy-to-follow guide for setting up the motors, power supply, and Bluetooth module connection.
