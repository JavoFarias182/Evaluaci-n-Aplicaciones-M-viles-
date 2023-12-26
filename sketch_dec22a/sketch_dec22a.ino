#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int PinIN1 = 7;
const int sensor_h = A0;
//Variable para almacenar el valor proveniente del sensor.
int sensorValue = 0;

LiquidCrystal_I2C lcd(0x21, 20, 4);

void setup() {
  // Comunicación serial
  Serial.begin(9600);

  //Iniciar el LCD
  lcd.init();
  //Encender luz de fondo
  lcd.backlight();

  //Configuramos los pines como salida
  pinMode(PinIN1, OUTPUT);

  // Posicionar el cursor en la esquina superior izquierda
  lcd.setCursor(2, 0);

  // Imprimir el mensaje "SISTEMA DE RIEGO"
  lcd.print("SISTEMA DE RIEGO");
}

void loop() {
  // Leer el valor del sensor de humedad
  sensorValue = analogRead(sensor_h);

  //Mostramos el porcentaje de humedad en pantalla
  lcd.setCursor(0, 1);
  lcd.print("HUMEDAD: ");
  if (sensorValue <= 250) {
    lcd.print("100%");
  } else if (sensorValue >= 251 && sensorValue <= 289) {
    lcd.print("95%");
  } else if (sensorValue >= 290 && sensorValue <= 309) {
    lcd.print("90%");
  } else if (sensorValue >= 310 && sensorValue <= 329) {
    lcd.print("85%");
  } else if (sensorValue >= 330 && sensorValue <= 349) {
    lcd.print("80%");
  } else if (sensorValue >= 350 && sensorValue <= 369) {
    lcd.print("75%");
  } else if (sensorValue >= 370 && sensorValue <= 389) {
    lcd.print("70%");
  } else if (sensorValue >= 390 && sensorValue <= 409) {
    lcd.print("65%");
  } else if (sensorValue >= 410 && sensorValue <= 429) {
    lcd.print("60%");
  } else if (sensorValue >= 430 && sensorValue <= 449) {
    lcd.print("55%");
  } else if (sensorValue >= 450 && sensorValue <= 469) {
    lcd.print("50%");
  } else if (sensorValue >= 470 && sensorValue <= 489) {
    lcd.print("45%");
  } else if (sensorValue >= 490 && sensorValue <= 509) {
    lcd.print("40%");
  } else if (sensorValue >= 510 && sensorValue <= 529) {
    lcd.print("35%");
  } else if (sensorValue >= 530 && sensorValue <= 549) {
    lcd.print("30%");
  } else if (sensorValue >= 550 && sensorValue <= 569) {
    lcd.print("25%");
  } else if (sensorValue >= 570 && sensorValue <= 589) {
    lcd.print("20%");
  } else if (sensorValue >= 590 && sensorValue <= 609) {
    lcd.print("15%");
  } else if (sensorValue >= 610 && sensorValue <= 629) {
    lcd.print("10%");
  } else if (sensorValue >=630  && sensorValue <= 639) {
    lcd.print("05%");
  } else if (sensorValue >= 640) {
    lcd.print("0%");
  }
  
  // Imprimir el mensaje "Humedad: X"
    lcd.setCursor(14, 1);
    lcd.print("V: ");
    Serial.println(sensorValue);
    lcd.print(sensorValue);
    delay(500);

  // Si el valor es mayor o igual a 640, significa que el suelo está seco
  if (sensorValue >= 640) {
    //Limpiamos una zona de la pantalla
    lcd.setCursor(3, 3);
    lcd.print("                ");
    //Indicamos que la planta se esta regando
    lcd.setCursor(3, 3);
    lcd.print("Regando...");
    delay(500);
    //Encendemos el motor de agua
    aguaON();
  }
  // Si el valor es menor o igual a 250, significa que el suelo está húmedo
  else if (sensorValue <= 250) {
    //Limpiamos una zona de la pantalla
    lcd.setCursor(2, 3);
    lcd.print("                ");
    // Imprimir el mensaje "ESTOY SATISFECHA"
    lcd.setCursor(2, 3);
    lcd.print("ESTOY SATISFECHA");
    delay(1000);
    //Apagamos el motor de agua
    aguaStop();
  }
}

void aguaON() {
  digitalWrite(PinIN1, HIGH);
}

void aguaStop() {
  digitalWrite (PinIN1, LOW);
}