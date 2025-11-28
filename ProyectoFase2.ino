#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

#define RELAY1 6
float umbralTemperatura = 28.0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(RELAY1, OUTPUT);
  digitalWrite(RELAY1, LOW);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" °C    Humedad: ");2
  Serial.println(h);

  if (t > umbralTemperatura) {
    digitalWrite(RELAY1, HIGH);
  } else {
    digitalWrite(RELAY1, LOW);
  }

  delay(2000);
}