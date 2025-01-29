# Line Following Robot

## Description
This project presents an autonomous robot that follows a line drawn on a surface using two digital sensors and DC motors controlled by an Arduino board. The robot detects the line and moves forward, backward, left, or right based on signals received from the sensors.

## Components Used
- **Arduino Board** (e.g., Arduino Uno)
- **4 x DC Motors**
- **H-Bridge Module** (e.g., L298N)
- **2 x Digital Line Sensors**
- **Breadboard**
- **Connection Cables**
- **LED for signaling**
- **Power Sources** (9V batteries or Li-Po accumulators)

## Connection Diagram
### Main Connections:
- DC motors are connected to the H-Bridge module.
- The H-Bridge control pins (IN1, IN2, IN3, IN4) are connected to the Arduino digital pins: **8, 9, 10, 11**.
- The ENABLE pins of the H-Bridge (ENR, ENL) are connected to the Arduino PWM pins: **3, 5**.
- The line sensors are connected to digital pins **6 and 7**.
- The H-Bridge power supply is provided by an external source (9V battery).
- The ground (GND) is common for Arduino, sensors, and the H-Bridge.

## Code Explanation
### Code Structure
The code is divided into three main parts:
1. **Initialization**: Defining the pins for motors, sensors, and LED, as well as setting speed and delay values.
2. **setup() Function**: Configuring the pins as inputs or outputs and initializing serial communication.
3. **loop() Function**: Monitoring sensor values and calling appropriate functions for movement or stopping.

### Main Functions:
- **forward()**: Starts both motors forward.
- **right() / left()**: Reverses motor direction to turn the robot.
- **stop()**: Stops all motors.
- **loop()**: Monitors sensors and decides movement accordingly.

### Movement Logic
1. If **both sensors detect the line (LOW, LOW)** → the robot moves forward.
2. If **only the left sensor detects the line (HIGH, LOW)** → the robot turns right.
3. If **only the right sensor detects the line (LOW, HIGH)** → the robot turns left.
4. If **no sensors detect the line (HIGH, HIGH)** → the robot stops.

## Conclusion
This project demonstrates a simple example of an autonomous robot using DC motors and line sensors. The robot can be further enhanced by adding additional sensors, such as IR or ultrasonic sensors, to improve navigation and obstacle avoidance.

## Usage Instructions
1. Connect the components according to the wiring diagram.
2. Upload the code to the Arduino board.
3. Power the system and place the robot on a drawn line.
4. Observe how the robot follows the line and adjusts its direction.

## Author
**Stoica Sergiu**  
_Publication Date: January 7, 2025_

