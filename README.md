# Object Counting and Gate Control System using ESP32

This project demonstrates a simple object counting and gate control system using an ESP32 microcontroller. The system utilizes an IR obstacle avoidance sensor to detect objects, a servo motor to control the gate, and an LED to indicate the presence of an obstacle.

## Components Used

* ESP32 Development Board

* IR Obstacle Avoidance Sensor

* Servo Motor

* LED

* Resistor (220 Ohm)

* Connecting Wires

* Breadboard


## Code Explanation

Library Inclusion: The ESP32Servo library is included to control the servo motor.

Pin Definitions: The GPIO pins for the sensor, LED, and servo motor are defined.

### Global Variables:

objectCount to keep track of the number of objects detected.
objectDetected to flag if an object is currently detected.
Setup Function:

Initializes serial communication at 115200 bps.
Sets up the sensor pin as an input, LED pin as an output, and attaches the servo motor to the specified pin.
Sets the initial position of the servo motor.
Loop Function:

Reads the state of the IR sensor.
If an object is detected (sensor state LOW) and it was not previously detected:
Sets the objectDetected flag.
Increments the objectCount.
Turns on the LED and opens the gate for 5 seconds using the openGate function.
If no object is detected (sensor state HIGH) and it was previously detected:
Resets the objectDetected flag.
Turns off the LED.
openGate Function:

Rotates the servo to open the gate (90 degrees) and waits for 5 seconds.
Rotates the servo back to close the gate (0 degrees).
Usage
Connect the components as per the circuit diagram.
Upload the code to the ESP32 using the Arduino IDE.
Open the Serial Monitor to view the object count and status messages.
Place objects in front of the IR sensor to see the system in action.
This project can be further expanded by integrating with IoT platforms to remotely monitor and control the gate, or by adding more sensors for enhanced functionality.
