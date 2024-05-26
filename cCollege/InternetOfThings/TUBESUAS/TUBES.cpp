#include <Stepper.h>

const int rainSensorPin = 25;
const int ldrSensorPin = 2;
const int buzzerPin = 5;
const int stepsPerRevolution = 2048;

#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  pinMode(rainSensorPin, INPUT);  // Set sensorPin as input
  analogReadResolution(10);
  pinMode(ldrSensorPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);         // Start serial communication at 9600 baud rate
  myStepper.setSpeed(5);
  Serial.begin(9600);
}

void loop() {
  rainSensor();
  delay(500);
  ldrSensor();
  delay(500);
  // stepper();
  // delay(1000);

if (ldrSensor() <= 300 && (rainSensor() >= 700 && rainSensor() <= 1000)) {
    myStepper.step(stepsPerRevolution);
}

}

int rainSensor() {
  // Serial.println("Raindrop : ");
  int nilai = analogRead(rainSensorPin);
  Serial.print("\nRaindrop: " + String(nilai));  // Read the digital value from the sensor and print it to the serial monitor
  // delay(50);
  // if (digitalRead(rainSensorPin)==0) {
  //   tone(buzzerPin, 250);
  // } else if (digitalRead(rainSensorPin)==1) {
  //   tone(buzzerPin, 0);
  // }
  return nilai;
}

int ldrSensor() {
  // int lightState = analogRead(ldrSensorPin);
  // if (lightState == HIGH) {
  //   Serial.println("Dark");
  // } else {
  //   Serial.println("Light");
  // }
  int nilai = (analogRead(ldrSensorPin));
  Serial.print("\nLDR: " + String(nilai));
  return nilai;
}

void stepper(){
  // step one revolution in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}

// #include <Stepper.h>

// const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

// // ULN2003 Motor Driver Pins
// #define IN1 19
// #define IN2 18
// #define IN3 5
// #define IN4 17

// // initialize the stepper library
// Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

// void setup() {
//   // set the speed at 5 rpm
//   myStepper.setSpeed(5);
//   // initialize the serial port
//   Serial.begin(115200);
// }

// void loop() {
//   // step one revolution in one direction:
//   Serial.println("clockwise");
//   myStepper.step(stepsPerRevolution);
//   delay(1000);

//   // step one revolution in the other direction:
//   Serial.println("counterclockwise");
//   myStepper.step(-stepsPerRevolution);
//   delay(1000);
// }
