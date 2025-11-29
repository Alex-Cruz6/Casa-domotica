// Importamos la librería del sensor DHT
#include <DHT.h>

// Definimos el pin donde está conectado el DHT22
#define DHTPIN 2

// Definimos el tipo de sensor (DHT22)
#define DHTTYPE DHT22

// Declaramos el objeto del sensor
DHT dht(DHTPIN, DHTTYPE);

// Pin del Arduino que controlará el módulo de relé
const int RELAY_PIN = 6;

// Umbral de temperatura a partir del cual se activa el relé
const float TEMPERATURE_THRESHOLD = 28.0;

void setup() {
  // Inicializamos la comunicación serial para ver lecturas en pantalla
  Serial.begin(9600);

  // Inicializamos el sensor DHT22
  dht.begin();

  // Configuramos el pin del relé como salida
  pinMode(RELAY_PIN, OUTPUT);

  // Aseguramos que el relé inicie apagado
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  // Leemos la humedad desde el sensor
  float humidity = dht.readHumidity();

  // Leemos la temperatura en grados Celsius
  float temperature = dht.readTemperature();

  // Verificamos si hubo error en la lectura
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error al leer el sensor DHT22");
    return; // Terminamos esta iteración del loop
  }

  // Mostramos las lecturas en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print(" °C   Humedad: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Verificamos si la temperatura supera el umbral configurado
  if (temperature > TEMPERATURE_THRESHOLD) {
    // Activamos el relé (encendemos la carga)
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Estado: Temperatura alta. Relé ACTIVADO.");
  } else {
    // Apagamos el relé
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Estado: Temperatura normal. Relé DESACTIVADO.");
  }

  // Pequeña pausa para evitar lecturas demasiado rápidas
  delay(2000);
}