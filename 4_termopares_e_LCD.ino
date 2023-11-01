#include <max6675.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Defina os pinos dos módulos Max6675 para cada termopar
int thermoDO[] = {2, 3, 4, 5}; // Pinos D2, D3, D4, D5 (MISO)
int thermoCS[] = {6, 7, 8, 9}; // Pinos D6, D7, D8, D9 (CS)
int thermoCLK[] = {10, 11, 12, 13}; // Pinos D10, D11, D12, D13 (SCK)

MAX6675 thermocouples[] = {MAX6675(thermoCLK[0], thermoCS[0], thermoDO[0]),
                           MAX6675(thermoCLK[1], thermoCS[1], thermoDO[1]),
                           MAX6675(thermoCLK[2], thermoCS[2], thermoDO[2]),
                           MAX6675(thermoCLK[3], thermoCS[3], thermoDO[3])};

LiquidCrystal_I2C lcd(0x27, 16, 2); // Configura o endereço do LCD como 0x27 e tamanho 16x2

void setup() {
  Serial.begin(9600);

  // Inicialize os módulos Max6675
  for (int i = 0; i < 4; i++) {
   
  }

  // Inicialize o LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  int temperaturaInteira[4];

  // Leia as temperaturas dos quatro termopares
  for (int i = 0; i < 4; i++) {
    temperaturaInteira[i] = int(thermocouples[i].readCelsius()); // Converte para inteiro
  }

  // Exiba as temperaturas no LCD
  lcd.setCursor(0, 0);
  lcd.print("T1:");
  lcd.print(temperaturaInteira[0]);
  lcd.print("C  T2:");
  lcd.print(temperaturaInteira[1]);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("T3:");
  lcd.print(temperaturaInteira[2]);
  lcd.print("C  T4:");
  lcd.print(temperaturaInteira[3]);
  lcd.print("C");

  delay(1000); // Aguarde um segundo antes de realizar a próxima leitura
}
