#include <Stepper.h>
#include <WiFi.h>
#define BLYNK_TEMPLATE_ID "TMPL6NrA97ZDC"   // Define Template ID here
#define BLYNK_TEMPLATE_NAME "JEMURAN IoT"  // Define Template Name here
#include <BlynkSimpleEsp32.h>

// Define pins and constants
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17
#define RAIN_SENSOR_PIN 25
#define LDR_SENSOR_PIN 2

#define BLYNK_AUTH_TOKEN "4rDUyYxIfU57gEnuos1to-3o0Sy6FsNF"

const int stepsPerRevolution = 4096;
const int positionOut = 5000;
const int positionIn = 0;

Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

int currentPosition = 0;
bool isManualControl = false;

char auth[] = "4rDUyYxIfU57gEnuos1to-3o0Sy6FsNF";
char ssid[] = "P4INCE";
char pass[] = "1stCentralBorneo";

BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(5);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, sensorRead);
}

BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
  isManualControl = true;
  if (buttonState == 1) { 
    runToNewPosition(positionOut);
    Blynk.logEvent("jemuran_keluar", "Jemuran Bergerak Keluar");
  } else {
    runToNewPosition(positionIn);
    Blynk.logEvent("jemuran_masuk", "Jemuran Bergerak Masuk Kedalam");
  }
}

void loop() {
  Blynk.run();
  timer.run();
}

void sensorRead() {
  if (!isManualControl) {
    int rainValue = analogRead(RAIN_SENSOR_PIN);
    Serial.print("Raindrop Sensor Value: ");
    Serial.println(rainValue);

    int ldrValue = analogRead(LDR_SENSOR_PIN);
    Serial.print("LDR Sensor Value: ");
    Serial.println(ldrValue);

    bool isRaining = rainValue < 700;
    bool isBright = ldrValue > 570;
    bool isDark = ldrValue < 300;

    Blynk.virtualWrite(V2, isRaining ? "Hujan" : "Tidak Hujan");
    Blynk.virtualWrite(V3, isBright ? "Cerah/Terang" : (isDark ? "Gelap" : "Normal"));

    if (!isRaining && isBright) {
      Serial.println("Tidak hujan dan terang - Jemuran keluar");
      runToNewPosition(positionOut);
      Blynk.logEvent("jemuran_keluar", "Jemuran Bergerak Keluar, Status: Terang/Cerah, Tidak Hujan");
    } else if (!isRaining && isDark) {
      Serial.println("Tidak hujan dan gelap - Jemuran masuk");
      runToNewPosition(positionIn);
      Blynk.logEvent("jemuran_masuk", "Jemuran Bergerak Masuk, Status: Gelap, Tidak Hujan");
    } else if (isRaining && isBright) {
      Serial.println("Hujan dan terang - Jemuran masuk");
      runToNewPosition(positionIn);
      Blynk.logEvent("jemuran_masuk", "Jemuran Bergerak Masuk, Status: Terang/Cerah, Hujan");
    } else if (isRaining && isDark) {
      Serial.println("Hujan dan gelap - Jemuran masuk");
      runToNewPosition(positionIn);
      Blynk.logEvent("jemuran_masuk", "Jemuran Bergerak Masuk, Status: Gelap, Hujan");
    }
  }

  if (isManualControl) {
    delay(2000);
    isManualControl = false;
  }
}

void runToNewPosition(int newPosition) {
  int steps = newPosition - currentPosition;
  if (steps != 0) {
    myStepper.step(steps);
    currentPosition = newPosition;
  }
}
