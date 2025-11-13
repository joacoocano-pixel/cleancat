#include <Servo.h>

Servo myservo;    // Crea el objeto servo
int pos = 0;      // Variable de posición del servo
int boton = 2;    // Pin donde conectamos el botón
int estadoBoton;  // Variable para leer el estado del botón

void setup() {
  myservo.attach(9);       // Servo en pin 9
  pinMode(boton, INPUT);   // Configura el pin del botón como entrada
}

void loop() {
  estadoBoton = digitalRead(boton);   // Lee el estado del botón

  if (estadoBoton == HIGH) {
    // Si el botón está presionado, el servo se mueve
    for (pos = 0; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
  // Si no se presiona el botón, el servo queda quieto
}
