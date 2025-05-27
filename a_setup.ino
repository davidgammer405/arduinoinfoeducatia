/**
 * Funcția de configurare Arduino.
 * 
 * Această funcție este apelată o singură dată la pornirea microcontrolerului.
 * Folosiți această funcție pentru a inițializa variabile, moduri de pini, a porni librării etc.
 */
void setup()
{
  lcd.begin(16, 2);//Initializare LCD cu 16 coloane și 2 rânduri
  //Initializarea pinilor
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, HIGH);
  pinMode(MOTOR, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);//Inițializare comunicație serială
}