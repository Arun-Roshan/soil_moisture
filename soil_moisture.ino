
#define BLYNK_TEMPLATE_ID "TMPL3V4yqR29I"
#define BLYNK_TEMPLATE_NAME "Irrigation System"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

char auth[] = "TNLQohhjJ4lcGHOl0uky_yZgtZYcmPri"; //Enter your Auth token
char ssid[] = "Arun"; //Enter your WIFI name
char pass[] = "12345678";  

BlynkTimer timer;

void moisture() {
  int value = analogRead(A0);
  value = map(value, 0, 1023, 0, 100);
  Blynk.virtualWrite(V0, value);
  lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print(value);
  lcd.print("  ");
  Serial.println(value);
}

void setup() {
  Serial.begin(9600);
  Wire.begin(D2, D1);
  lcd.init();
  lcd.backlight();
  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("IrrigationSystem");
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100L, moisture);

}
void loop() {
  Blynk.run();
  timer.run();
}