void setup() {
  lcd.begin(16, 2);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(BUTTON, INPUT);
  
  digitalWrite(MOTOR, LOW);

  Serial.begin(9600);

  // Load calibration from EEPROM
  //EEPROM.get(0, setupled);
  //EEPROM.get(1, apauda);
} 