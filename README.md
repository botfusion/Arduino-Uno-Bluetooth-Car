# Arduino-Uno-Bluetooth-Car

## Description:

This is a Bluetooth-controlled car based on Arduino UNO. It can be controlled using any smartphone.

## Important Note:

Do not program the Arduino board when it is connected to the Motor Driver. You have a risk of damaging your Arduino as well as your computer if your computer is connected to the Arduino.

## Components List

| No. | Component                    | Quantity |
|-----|------------------------------|----------|
| 1   | Arduino Uno                  | 1        |
| 2   | Motor Driver Shield (L293D)  | 1        |
| 3   | HC-05 Bluetooth Module       | 1        |
| 4   | Logic Level Converter        | 1        |
| 5   | 18650 mAh Battery            | 2        |
| 6   | 18650 Battery Case           | 1        |
| 7   | Push Button Switch           | 1        |
| 8   | 4 Wheel Car Chassis          | 1        |
| 9   | TT Gear Motor                | 4        |
| 10  | Connecting Wires             | -        |
| 11  | Soldering Iron               | -        |
| 12  | Arduino Car App              | -        |

## Picture:

![Image Alt](https://github.com/botfusion/Arduino-Uno-Bluetooth-Car/blob/eeacdaf4c2831f9e4c365ec227d9176d667b5ac4/img/Front%20View.jpg)  
![Image Alt](https://github.com/botfusion/Arduino-Uno-Bluetooth-Car/blob/eeacdaf4c2831f9e4c365ec227d9176d667b5ac4/img/Top%20view.jpg)

## Explanation:

### Arduino Bluetooth Controlled Car

This is a simple project with a twist in the circuit and Bluetooth communication part. We are using an **Arduino Uno** and a **Motor Driver Shield** to control 4 **TT Gear Motors**.

#### Why Do We Need to Use a Motor Driver?

Although the motors operate at **5V** and the Arduino can provide **5V**, **current** and **voltage** are two different things. The Arduino cannot provide sufficient current to drive the motors, which is why a **Motor Driver** is required.

#### Power Supply

We are using two **18560 batteries** connected in series, which gives a total of **7.4V** (3.7V + 3.7V). These batteries power all the electronics in the system: 

- Arduino Uno
- Motor Driver Shield
- Bluetooth Sensor

#### Communication Between Arduino and HC05 Bluetooth Sensor

Now comes the tricky part. The **Arduino** operates on **5V logic**, while the **HC05 Bluetooth sensor** operates on **3.3V logic**. If any digital pin is connected directly to the pins of the HC05, it could damage the Bluetooth sensor.

##### Solution: Logic Level Converter

To solve this problem, we use a **logic level converter** to safely interface the **5V logic** of the Arduino with the **3.3V logic** of the HC05 Bluetooth sensor.

## Circuit Diagram:

![Image Alt](https://github.com/botfusion/Arduino-Uno-Bluetooth-Car/blob/eeacdaf4c2831f9e4c365ec227d9176d667b5ac4/img/circuit%20diagram.png)

### Project Overview

This is a simple project that involves controlling a set of motors using an Arduino Uno and a Motor Driver Shield. For this project, we will be using hookup wires and modules, so there's no need for a PCB or schematic diagram. However, I have created a circuit diagram using **Fritzing** for reference.

#### Motor Connections

There are four motors:

- **FMR (Front Motor Right)**: Connected to Port 4 of the Motor Driver Shield
- **FML (Front Motor Left)**: Connected to Port 1
- **BMR (Back Motor Right)**: Connected to Port 3
- **BML (Back Motor Left)**: Connected to Port 2

As the names suggest, **FMR** stands for **Front Motor Right**, and you can infer the others from this naming convention.

#### Power Supply

We use **two 18560 batteries** in series, providing a total of **7.4V** (3.7V + 3.7V). These batteries power the entire system, including:

- Arduino Uno
- Motor Driver Shield
- Bluetooth Module

The push button will help control the power flow from the battery to the motor driver and other components.
![Image Alt](https://github.com/botfusion/Arduino-Uno-Bluetooth-Car/blob/eeacdaf4c2831f9e4c365ec227d9176d667b5ac4/img/bluetooth%20pcb%20design.png)

#### Bluetooth Module Connection

To connect the **Bluetooth Module**, follow these steps:

##### 1. Soldering Extra Pins to the Motor Driver Shield

- First, solder the **A0-A5 pins** to the Motor Driver Shield. These are clearly labeled on the shield.
- After soldering, these pins will connect directly to the **A0-A5 pins** on the Arduino Uno.

##### 2. Soldering 5V, GND, and Vin Pins

- Next, solder the **5V**, **GND**, and **Vin** pins on the Motor Driver Shield. This is done in the same way as the A0-A5 pins.
- Once soldered, these pins will be directly connected to the **5V**, **GND**, and **Vin** pins on the Arduino Uno.

##### 3. Soldering the 3.3V Pin

- There is one more soldering step for the **3.3V pin**. By default, this pin on the Arduino coincides with the pin on the Motor Driver Shield.
- **Desolder** the 3.3V pin from the Motor Driver.
- After desoldering, **resolder** a new pin in the same position as the previous pins. This pin will be used for the **orange-colored wire** in the circuit (please refer to the circuit diagram above).

## Bluetooth Configuration:

Before you start setting up the app, ensure that the **HC-05 Bluetooth module** is properly configured to work with the Arduino. The module comes with default settings that are usually compatible with most smartphones, but in some cases, you may need to adjust the baud rate or pairing settings.

1. **HC-05 Baud Rate**: The default baud rate for the HC-05 module is **9600**. Ensure that the Arduino is programmed to communicate with this baud rate.

2. **Password for HC-05**: By default, the HC-05 module is usually paired with a password of **"1234"** or **"0000"**. Make sure you use one of these passwords when pairing your device.

3. **LED Indicator**: The HC-05 module will have an LED indicator that blinks when it's not paired. Once connected to your smartphone, the LED should turn solid, indicating a successful connection.

For a more detailed guide on configuring your HC-05 Bluetooth module, including using AT commands, check out this [HC-05 AT Commands Tutorial](https://lastminuteengineers.com/hc05-at-commands-tutorial/).

Once configured, you can move on to the app setup.

## Setting Up App:

### Installing the App

All you have to do is **install the app**. You can download similar apps as well, and all of them should work for this project. Just remember to **turn off the internet connection**, otherwise, you'll be bombarded with ads.

### Connecting to the HC-05 Bluetooth Module

1. **Turn ON the Bluetooth** of your smartphone.
2. **Connect** to the **HC-05 module**. The default password for the HC-05 module should be either:
   - **“1234”**
   - **“0000”**

### Configuring the App

Once connected to the HC-05 module:

1. Open the app again.
2. Go to the **settings menu** and click on the first option: **Connect to Module**.
3. If the connection is successful, the button should turn **green**, indicating that your smartphone is connected to the HC-05 module.

![Image Alt](https://github.com/botfusion/Arduino-Uno-Bluetooth-Car/blob/eeacdaf4c2831f9e4c365ec227d9176d667b5ac4/img/app%20setting.png)

## Android Bluetooth App Link:

[Download the app here](https://play.google.com/store/apps/details?id=com.SanitTech.RCBluetoothControllerHC05)

## Conclusion:

In this project, we successfully built a Bluetooth-controlled car using an **Arduino Uno**, **Motor Driver Shield**, and a **HC-05 Bluetooth module**. By utilizing a motor driver, we ensured that the Arduino could provide sufficient current to drive the motors. We also addressed the voltage differences between the Arduino and Bluetooth module using a **logic level converter**. With a simple push button switch and the use of **two 18560 batteries**, we created a fully functional system that can be controlled via a smartphone app.

By following the outlined steps, you can replicate this project or modify it to suit your needs. This project not only demonstrates the power of combining basic electronics and wireless communication but also opens the door to further innovations in remote-controlled systems.

With just a few components and a bit of setup, you can control your very own Bluetooth-enabled robotic car. Happy building! 

#  #Team BotFusion

## Reference:

1. [L293d Motor Driver Shield Tutorial](https://lastminuteengineers.com/l293d-motor-driver-shield-arduino-tutorial/)
2. [HC05 Bluetooth Module Tutorial](https://lastminuteengineers.com/hc05-bluetooth-arduino-tutorial/)
3. [Logic Level Converter Guide](https://learn.sparkfun.com/tutorials/bi-directional-logic-level-converter-hookup-guide/all)
