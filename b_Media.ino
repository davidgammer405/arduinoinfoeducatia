int Media() {
  lcd.clear();
  lcd.print("Se pregateste settopul");
  lcd.setCursor(0, 1);
  lcd.print("settopul");
  delay(3000);
  lcd.clear();

  lcd.print("Mediu uscat");
  lcd.setCursor(0, 1);
  lcd.print("apasa pe buton");
  while (digitalRead(BUTTON) == HIGH) {}  // Wait for press
  delay(500);                             // debounce
  while (digitalRead(BUTTON) == LOW) {}   // Wait for release
  for (int i = 1; i < 500; i++) {
    bot = (bot + udapa()) / i;
  }

  lcd.clear();
  lcd.print("Uscat setat");
  delay(2000);
  lcd.clear();

  lcd.print("Pamant ud");
  lcd.setCursor(0, 1);
  lcd.print("apasa pe buton");
  while (digitalRead(BUTTON) == HIGH) {}  // Wait for press
  delay(500);                             // debounce
  while (digitalRead(BUTTON) == LOW) {}   // Wait for release
  for (int i = 1; i < 500; i++) {
    top = (top + udapa()) / i;
  }

  lcd.clear();
  lcd.print("Settop completat");
  delay(2000);
  lcd.clear();

  setupled = true;
  apauda = (bot + top) / 2;

  //EEPROM.put(2,bot);
  //EEPROM.put(3,top);
  //EEPROM.put(0, settopled);
  //EEPROM.put(1, apauda);


  return apauda;
}
