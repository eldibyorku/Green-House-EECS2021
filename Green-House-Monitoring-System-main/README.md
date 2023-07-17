# Green-House-Monitoring-System
## **INTRODUCTION:** 

The optimum growth of the plant can not only be achieved by maintaining the soil moisture level. Plants do require maintained temperature, humidity, and light intensity for ideal growth. To achieve the ideal growth of the plant I have added all these features by making real time operating system using Arduino and various sensors. I used C++ and JAVA coding language to make this automated system work.

#### **PROJECT DEMONSTRATION LINK** 
https://www.youtube.com/watch?v=oYrN-Oa7CmY 

## **ABOUT THIS PROJECT:**
 
This was my first-year embedded project. I made this project in 2 different parts. 
 
#### Part-1.Automatic Real Time Operation using Arduino + Various Sensors + C++: 
To make this Automatic Real Time Operation based embedded project, I used the C++ programming language. In this operation Arduino fetches and decodes the data from the sensors. After decoding the data Arduino compares the data with an algorithm (written in code) and executes the data to output devices to operate them in real time.    
 
#### Part-2.Manual Real Time Operation Using Arduino + Various Sensors + JAVA + JAVA FX (To enable GUI Feature): 
To make this Manual Real Time Operation based embedded project. I used the JAVA programming language thanks to my professor Dr. James Smith who helped me to write this code. To make changes in the operation I used the JAVA GUI feature to operate the output devices through Arduino.

## **SYSTEM SETUP:**

<p img align="center">
<img width="900" src="https://user-images.githubusercontent.com/89041406/129837203-49164fed-bd71-4a82-bbc2-65ce2ca6fcae.png">
</p>

## **CODE INSTRUCTION:**

#### **Automatic Part:**
Copy “AutomaticCode.txt” code from the Automatic Code C++ folder and paste into ArduinoIDE. Also, I have used a 20x4 I2C LCD display to show all the data of each sensor. To make this LCD Display work add I2C LCD library into ArduinoIDE from this link.(https://educ8s.tv/arduino-20x4-character-lcd/). Also, add the DHT22 library to make the DHT22 temperature sensor work. 
 
#### **Manual Part:**
For the manual part I have written my code in IntelliJ IDEA and the manual part code is in the Manual Code JAVA folder. To make this code work create a “Main” Class in java then copy and paste the code from the Main.java. Along with the main class create a 2 sub-class with the name of “SerialPortService” and “DataController” copy code from SerialPortService.java and DataController.java and paste them respective class.To enable JAVAFX to make JAVA GUI work please refer to this link (https://www.jetbrains.com/help/idea/2020.3/javafx.html#download-javafx). Moreover, to enable the serial communication between JAVA and Arduino add Maven Library “com.fazecast:jserialComm”.Also, Manual Code JAVA folder there is one file with the name "ManualCode.txt" copy this file in Arduino IDE. So that Arduino can work using JAVA code.    

## **TECHNICAL REQUIREMENTS/SPECIFICATION:**
<p img align = "right">
<img align="right" width="400" height="600" src="https://user-images.githubusercontent.com/89041406/129835025-3b3f2026-ac99-4098-981e-5456e689937f.png">
</p>

<p img align = "left">
<img width="400" height="500" src="https://user-images.githubusercontent.com/89041406/129836575-6a5db761-a516-4570-b137-9ca93419ef42.png">
</p>

<br>
</br>
<br>
</br>

## **CODE REFERENCE:**

###### **20x4 LCD Display:**
https://educ8s.tv/arduino-20x4-character-lcd/

###### **DHT 11 Temperature and Moisture sensor:**
https://www.brainy-bits.com/post/how-to-use-the-dht11-temperature-and-humidity-sensor-with-an-arduino

###### **Delay code for Arduino:**
https://www.programmingelectronics.com/arduino-sketch-with-millis-instead-of-delay/

###### **Pushbutton Position FOR JAVA GUI:**
http://tutorials.jenkov.com/javafx/button.html
