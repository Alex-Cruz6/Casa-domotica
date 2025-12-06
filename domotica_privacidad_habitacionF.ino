#include <Servo.h>

// --- Objetos y pines ---
Servo persiana;

const int PIN_PIR   = 2;   // Entrada del PIR (o interruptor)
const int PIN_LED   = 13;  // LED que simula la luz de la habitación
const int PIN_SERVO = 9;   // Servo SG90 (persiana)

// Ángulos de la persiana
const int ANGULO_ABIERTO = 0;   // Persiana abierta
const int ANGULO_CERRADO = 90;  // Persiana cerrada

// Tiempo de retención (HOLD) en milisegundos
const unsigned long TIEMPO_HOLD = 5000; // 5 segundos

bool hayPresencia = false;
unsigned long ultimoMovimiento = 0;

void setup() {
  persiana.attach(PIN_SERVO);

  pinMode(PIN_PIR, INPUT);   // Entrada digital (interruptor → 0/1)
  pinMode(PIN_LED, OUTPUT);  // Salida para la luz

  // Estado inicial: sin presencia
  persiana.write(ANGULO_ABIERTO); // Persiana abierta
  digitalWrite(PIN_LED, LOW);     // Luz apagada
}

void loop() {
  int lecturaPIR = digitalRead(PIN_PIR);

  if (lecturaPIR == HIGH) {
    // Se detecta movimiento (PIR = 1)
    hayPresencia = true;
    ultimoMovimiento = millis();

    // Modo ocupado
    persiana.write(ANGULO_CERRADO); // Cerrar persiana
    digitalWrite(PIN_LED, HIGH);    // Encender luz
  } else {
    // No hay movimiento ahora mismo
    if (hayPresencia) {
      // Verificar si ya pasó el tiempo de retención
      if (millis() - ultimoMovimiento >= TIEMPO_HOLD) {
        hayPresencia = false;

        // Volver al estado normal
        persiana.write(ANGULO_ABIERTO); // Abrir persiana
        digitalWrite(PIN_LED, LOW);     // Apagar luz
      }
    }
  }
}
