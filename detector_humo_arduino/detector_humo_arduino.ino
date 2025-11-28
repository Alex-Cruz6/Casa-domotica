// Sistema de detección de humo con indicadores LED y alarma sonora

const int PIN_SENSOR_HUMO = A5;
const int PIN_LED_ROJO = 11;
const int PIN_LED_AMARILLO = 12;
const int PIN_LED_VERDE = 13;
const int PIN_ALARMA = 10;

const int UMBRAL_SEGURO = 930;
const int UMBRAL_PELIGRO = 960;
const int FRECUENCIA_ALARMA = 440;

void setup() {
  Serial.begin(9600);
  
  pinMode(PIN_LED_ROJO, OUTPUT);
  pinMode(PIN_LED_AMARILLO, OUTPUT);
  pinMode(PIN_LED_VERDE, OUTPUT);
  pinMode(PIN_ALARMA, OUTPUT);
}

void loop() {
  int nivelHumo = analogRead(PIN_SENSOR_HUMO);
  
  if (nivelHumo < UMBRAL_SEGURO) {
    estadoSeguro();
  } 
  else if (nivelHumo < UMBRAL_PELIGRO) {
    estadoAdvertencia();
  } 
  else {
    estadoPeligro();
  }
  
  delay(500);
}

/**
 * Activa el estado seguro: LED verde encendido, alarma desactivada
 */
void estadoSeguro() {
  digitalWrite(PIN_LED_VERDE, HIGH);
  digitalWrite(PIN_LED_AMARILLO, LOW);
  digitalWrite(PIN_LED_ROJO, LOW);
  noTone(PIN_ALARMA);
  Serial.println("ESTAS FUERA DE PELIGRO");
}

/**
 * Activa el estado de advertencia: LED amarillo encendido, alarma desactivada
 */
void estadoAdvertencia() {
  digitalWrite(PIN_LED_VERDE, LOW);
  digitalWrite(PIN_LED_AMARILLO, HIGH);
  digitalWrite(PIN_LED_ROJO, LOW);
  noTone(PIN_ALARMA);
  Serial.println("OJO! EL PELIGRO SE ACERCA");
}

/**
 * Activa el estado de peligro: LED rojo encendido, alarma activada
 */
void estadoPeligro() {
  digitalWrite(PIN_LED_VERDE, LOW);
  digitalWrite(PIN_LED_AMARILLO, LOW);
  digitalWrite(PIN_LED_ROJO, HIGH);
  tone(PIN_ALARMA, FRECUENCIA_ALARMA);
  Serial.println("ESTAS EN PELIGRO");
}