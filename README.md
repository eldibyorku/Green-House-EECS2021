Green-House-Monitoring-System
INTRODUCTION:
This is a second year engineering project for EECS 2021. This system is designed to monitor the soil moisture level, temperature, humidity, and light intensity to create the ideal environment for plant growth. This is acomplished by making a real time operating system using Arduino and the various sensors. The code for this project is done in C++ and Java.



CODE INSTRUCTION:
Automatic Part:
Copy “AutomaticCode.txt” code from the Automatic Code C++ folder and paste into ArduinoIDE. A 20x4 I2C LCD display is used to show the data from each sensor. To make this LCD Display work add I2C LCD library into ArduinoIDE, link:(https://educ8s.tv/arduino-20x4-character-lcd/). Additionally, add the DHT22 library to make the DHT22 temperature sensor work.

Manual Part:
Main.java, DataController and SerialPosrialPortService are the Java classes that contain the logic for data processing and warning messages. To enable JAVAFX to make JAVA GUI work please refer to this link (https://www.jetbrains.com/help/idea/2020.3/javafx.html#download-javafx). Moreover, to enable the serial communication between JAVA and Arduino add Maven Library “com.fazecast:jserialComm”.Also, Manual Code JAVA folder there is one file with the name "ManualCode.txt" copy this file in Arduino IDE.

CODE REFERENCE:
20x4 LCD Display:
https://educ8s.tv/arduino-20x4-character-lcd/

DHT 11 Temperature and Moisture sensor:
https://www.brainy-bits.com/post/how-to-use-the-dht11-temperature-and-humidity-sensor-with-an-arduino

Delay code for Arduino:
https://www.programmingelectronics.com/arduino-sketch-with-millis-instead-of-delay/

Pushbutton Position FOR JAVA GUI:
http://tutorials.jenkov.com/javafx/button.html
