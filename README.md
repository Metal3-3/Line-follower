
# Line follower robot STARK-F1
<img width="520" height="295" alt="Line_Follower" src="https://github.com/user-attachments/assets/637c3ae2-d381-46e0-a54f-6847e329917d" />

My first ever serious project. STARK-F1 is a line follower robot that uses arduino nano as the micro controller. I wanted to make this after seeing how much line follower kits cost. This robot can be set to faster speeds and can be used in competitions. Right now its set to 70 speed (out of 255) so with proper changes it can be way faster and complete parkours.

# Main components
<img width="757" height="694" alt="lfstrak" src="https://github.com/user-attachments/assets/5eea5a5d-01c7-40c1-aa51-4d7932dd4efd" />

# Performance

- Sensor: QTR-8A
- Controller: Arduino Nano
- Motor Driver: TB6612FNG
- Control Algorithm: PID
- Motors: 12V 1200 RPM
- Battery: 2S Li-Po
- Wheel Diameter: ~40 mm
- Chassis: 171 × 112 × 4 mm

# softwares
- tinkercad 
- online ide/compilers
- arduino ide

# chassis info
it has been designed in tinkercad with the wheels, motor holders, and silicone wheel mold
i designed it getting inspriation from other line follower robots and from my knowledge. The hardest part was designing the mold pretty much. The chassis uses m3 holes (3mm) with 4 holes on side for the motor holder, 4 on the front for the qtr-8a and 4 in the middle for the arduino uno shield.
The diameters are 112 x 171 x 4

  
# Code info
i got help with claude ai in the code. Through the code i used turkish for the different variables and even the names. 
Main.ino is the main file that includes the main variables and calibration. 
MotorKontrol.ino is for motor controll, 
Sensoroku.ino is for reading the sensor. 
SensorOkuYaz is to read the sensor and output it. 
## Main.ino
tabanhız is the main speed and right now it is 70. İf you want it faster you might have to change kp and kd (pid variables.)
ekhız is add on speed right now 0 and not bing used it will be relevant once i update the code for it to be fast and accurate.

## License

### Code
MIT License

### 3D Models
CC BY 3.0
