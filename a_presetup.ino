// Librariile folosite
#include <LiquidCrystal.h>
#include <EEPROM.h>

// Definirea pinilor pentru Arduino Uno
#define SENSOR_PIN   A0
#define GREEN_LED    3
#define RED_LED      2
#define MOTOR        5
#define BUTTON       4
#define IR           6

// Definirea pinilor LCD
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;

// Definirea variabilelor
bool setupled       = false; // Variabila pentru a verifica dacă setup-ul a fost realizat
int  apauda         = 0;     // Media de udare
int  bot, top;               // Valori pentru umiditate uscată și udă
int  index;                  // Index pentru EEPROM
int  moisture;               // Valoarea de umiditate citită de la senzor
int  pagina         = 0;     // Pagina curentă pentru afișare
bool onof           = 0;     // Starea ON/OFF pentru udare automată
int  moistureper;            // Procentajul de umiditate

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Inițializarea obiectului LCD
