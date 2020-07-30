# Arduino Smart wheelchair Demo
 This is a small demo of gesture controlled wheelchair. It is controlled using hand gestures wirelessly. This is just small prototype but actual working product can be made using same codebase with slight modifications as per changes in hardwares used. It has two systems :
 
 ## 1. Reciever system
  It receives the control signals  through RF receiver and controls the motors and other parts.
  
  ### Hardwares used
   * Arduino UNO
   * 433MHZ RF receiver
   * L298N Motor Driver Module
   * 4 DC motors + 4 Wheels
   * One BO motor for moving wheelchair up and down(any motor or actuator can be used)
   * 9V battery
  
 ## 2. Transmitter system
  It is wearable device and can be embedded on top part of gloves. It monitors hand movements and sends control signals through RF transmitter 
  
  ### Hardwares used
  
  * Arduino Lilypad
  * MPU 6050 3-axis Gyroscope + 3-axis Acceleromter
  * 433MHZ RF transmitter
   * 3.7 volt Li-ion battery
   
    
  
 
