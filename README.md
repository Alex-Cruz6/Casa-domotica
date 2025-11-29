Sistema Domótico – Proyecto Fase 2 (Arquitectura de Computadoras)
Este repositorio contiene el desarrollo, simulación y código fuente de la Fase 2 del Proyecto de Domótica, realizado para la asignatura Arquitectura de Computadoras.
El objetivo de esta fase es simular el funcionamiento real de los diferentes módulos del sistema utilizando sensores y actuadores conectados a Arduino UNO.
La documentación completa del proyecto se encuentra en el archivo PDF entregado oficialmente.
________________________________________
🔧 Descripción General del Proyecto
El sistema domótico integra múltiples sensores y actuadores que permiten:
•	Medir variables ambientales (temperatura, humedad, luz, humo).
•	Detectar movimiento o presencia.
•	Activar actuadores como servomotores, buzzers, relés y LEDs.
•	Simular comportamientos reales de un hogar inteligente.
Cada integrante del equipo desarrolló un módulo independiente, pero funcionalmente integrado a la arquitectura general del sistema.
________________________________________
🧩 Módulos del Proyecto
1. Control de Confort Térmico (Beatriz Martínez)
Simulador: SimulIDE
•	Sensor DHT22 (temperatura y humedad)
•	Módulo Relé
•	Activación de carga cuando la temperatura supera 28 °C
•	Evidencias de lectura serial y funcionamiento en SimulIDE
Código:
/control_termico_dht22_rele/
________________________________________
2. Control de Privacidad con Sensor PIR (Vladimir)
Simulador: SimulIDE
•	Sensor HC-SR501 PIR
•	Servo SG90
•	Movimiento del servo al detectar presencia
Código:
/control_privacidad_servo/
________________________________________
3. Detector de Humo (Alex Martínez)
Simulador: Tinkercad
•	Sensor MQ-2
•	Buzzer
•	LED de alerta
•	Modo normal / alerta / retención
Código:
/detector_humo_arduino/
________________________________________
4. Sistema de Iluminación Automática (William)
Simulador: Tinkercad
•	Sensor PIR
•	LED RGB
•	Iluminación reactiva a presencia
Código:
/iluminacion_inteligente_pir/
________________________________________
▶️ Video de Funcionamiento
El video de funcionamiento, donde se explica la simulación de cada módulo, se encuentra disponible en el siguiente enlace:
[Enlace al video de presentación](https://udbedu-my.sharepoint.com/:f:/g/personal/mm110166_alumno_udb_edu_sv/IgDcFWrE9eS5TLfCxm3DdwofAWHDj_99esckot8E48BMRI0?e=ZCPVur)
________________________________________
📁 Código del Proyecto
Cada carpeta contiene:
•	Código .ino
________________________________________
🛠 Simuladores Utilizados
•	SimulIDE 1.1.0
•	Tinkercad Circuits
•	Arduino IDE 2.3.x
Los simuladores varían por integrante debido a las características del módulo desarrollado.
________________________________________
👨‍💻 Integrantes
•	Beatriz Martínez
•	Vladimir Mendoza
•	William Barahona
•	Alex Martínez
________________________________________
📄 Licencia
Proyecto académico.
Uso permitido únicamente con fines educativos.
