# Distance controlled water pump

#### WHAT IS THIS
This is a part of the project that I made for an art installation titled _Drip(s)_, Which was shown on Greycube Goethe institut. The goal is very simple - when people walk close to the installation, water pump starts running and makes water dripping. 


#### ABOUT THE CIRCUIT
##### PUMP
Though it sounds very easy but there are still some steps need to be very careful. For example, if you use Arduino, it only provides 5v to power the pump, but what you usually found selling is 12VDC pump, in this case a relay is needed. However, if your requirement is just circulating small flow, 5VDC water pump is enough. Here is the list of components:

- 1x Peristaltic pump (4v-6v DC)
- 1x 1N4001 Diode
- 1x PN2222 NPN Transistor 
- 1x Arduino Uno microcontroller

Basically you can see a peristaltic pump as a dc motor, it will work regardless of the how the voltage source is connected to it in regards to polarity. It also can cause back emf that can possibly damage a microcontroller or any electronic device. So the diode here is placed parallel reverse biased to protect from these harmful effects. The transistor is used for current amplification, because arduino does not output enough current to drive the peristaltic pump. The base of transistor is connected to arduino's digital pin (I used digial pin 10) that controlls the pump's on and off. Here is the circuit:

![peristaltic-pump-circuit-with-an-arduino-microcontroller](https://user-images.githubusercontent.com/41480919/44308312-1c8e5a00-a381-11e8-8733-3237d2589321.png)

##### Ultrasonic sensor
I use seeed ultrasonic sensor for distance measuring, since we already used arduino's 5v output for the pump, so the 3.3V is used for powering the sensor, and A3 is the signal input. 

##### Decoupling 
Because I also use two piezo sensors with load resistors in the another circuit, the high voltage circuit makes the piezo result very noisy. So for both the 5v and 3.3v power supplies, I put 100 µF plus 100nF capacitors between them.  

##### Code
The code to turn on a peristaltic pump for 5 seconds every 30 seconds is shown below. 
