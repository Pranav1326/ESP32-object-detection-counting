#include <ESP32Servo.h>

#define SENSOR_PIN 13  // ESP32 pin GPIO13 connected to OUT pin of IR obstacle avoidance sensor
#define LED_PIN 14     // ESP32 pin GPIO14 connected to the Anode of the LED
#define SERVOMOTOR_PIN 15 // ESP32 pin GPIO15 connected to the servo motor signal pin

Servo myservo;  // create servo object to control a servo

int objectCount = 0;
bool objectDetected = false;

void setup() {
    Serial.begin(115200);  // initialize serial communication at 115200 bits per second
    pinMode(SENSOR_PIN, INPUT);  // initialize the ESP32 pin as an input
    pinMode(LED_PIN, OUTPUT);  // initialize the ESP32 pin as an output
    myservo.attach(SERVOMOTOR_PIN);  // attach the servo on SERVOMOTOR_PIN to the servo object
    myservo.write(0);  // set initial position of the servo
}

void loop() {
    int state = digitalRead(SENSOR_PIN);  // read the state of the input pin

    if (state == LOW && !objectDetected) {
        objectDetected = true;  // set the object detected flag
        objectCount++;  // increment the object count
        Serial.print("Object Count: ");
        Serial.println(objectCount);
        Serial.println("The obstacle is present");
        digitalWrite(LED_PIN, HIGH);  // turn on the LED
        openGate();  // open the gate for 5 seconds
    } else if (state == HIGH && objectDetected) {
        objectDetected = false;  // reset the object detected flag
        Serial.println("The obstacle is NOT present");
        digitalWrite(LED_PIN, LOW);  // turn off the LED
    }

    delay(100);
}

void openGate() {
    myservo.write(90);  // rotate the servo to open position
    delay(5000);  // wait for 5 seconds
    myservo.write(0);  // rotate the servo back to closed position
}
