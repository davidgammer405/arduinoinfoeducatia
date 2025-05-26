#include <LiquidCrystal.h>
#include <EEPROM.h>

#define SENSOR_PIN A0
#define GREEN_LED 3
#define RED_LED 2
#define MOTOR 5
#define BUTTON 4

const int rs = 13, en =12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
bool setupled = false;
int apauda = 0;  // moisture threshold
int bot, top;
int index;
int moisture;
int pagina;
bool onof = 1;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
