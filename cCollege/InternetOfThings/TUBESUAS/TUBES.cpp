#define BLYNK_AUTH_TOKEN "8gTndKZHrpDzGZo3XSH3hi-sNTnqB5Aq"
#define BLYNK_TEMPLATE_ID "TMPL6JIY2uARx"
#define BLYNK_TEMPLATE_NAME "CONTROL AND MONITORING JEMURAN IoT"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Stepper.h>

#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17
#define RAIN_SENSOR_PIN 33
#define LDR_SENSOR_PIN 32
#define STEPS 100

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Infomu tah Infoku";
char pass[] = "ngopi1234";

Stepper myStepper(STEPS, IN1, IN3, IN2, IN4);

bool isClothesOutside = false;
bool isSystemOn = false;  // Variabel untuk status sistem

void moveClothesOutside() {
  Serial.println("Jemuran Keluar!");
  myStepper.step(7500);
  isClothesOutside = true;
  Blynk.logEvent("jemuran_keluar", "Jemuran Keluar!");
}

void moveClothesInside() {
  if (isClothesOutside) {
    Serial.println("Jemuran Masuk!");
    myStepper.step(-7500);
    isClothesOutside = false;
    Blynk.logEvent("jemuran_masuk", "Jemuran Masuk!");
  }
}

// Fungsi untuk menangani perubahan status tombol On/Off
BLYNK_WRITE(V3) {
  isSystemOn = param.asInt();
  if (!isSystemOn && isClothesOutside) {
    moveClothesInside();  // Memanggil fungsi untuk memindahkan jemuran ke dalam jika tombol Off ditekan
  } else if (isSystemOn) {
    Serial.println("Sistem Dinyalakan");
  } else {
    Serial.println("Sistem Dimatikan");
  }
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(RAIN_SENSOR_PIN, INPUT);
  pinMode(LDR_SENSOR_PIN, INPUT);
  myStepper.setSpeed(200);
}

void loop() {
  Blynk.run();

  if (isSystemOn) {  // Hanya menjalankan sistem jika isSystemOn true
    int ldrValue = analogRead(LDR_SENSOR_PIN);
    ldrValue = constrain(ldrValue, 0, 1023);
    int rainValue = analogRead(RAIN_SENSOR_PIN);
    rainValue = constrain(rainValue, 0, 1023);
    
    Serial.print("Rain Sensor: ");
    Serial.println(rainValue);
    Serial.print("LDR Sensor: ");
    Serial.println(ldrValue);
    
    Blynk.virtualWrite(V1, rainValue);
    Blynk.virtualWrite(V2, ldrValue);

    bool isRain = rainValue < 700;
    bool isLight = ldrValue > 750;
    bool isDark = ldrValue <= 750;

    if (!isClothesOutside) {
      if (isLight && !isRain) {
        moveClothesOutside();
      }
    } else {
      if (isRain || isDark) {
        moveClothesInside();
        isSystemOn = false;  // Mematikan sistem ketika jemuran masuk
        Blynk.virtualWrite(V3, isSystemOn);  // Memperbarui status tombol di Blynk
      }
    }
  }

  delay(1000);
}
