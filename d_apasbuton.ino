void apasbuton() {
  int butat = digitalRead(BUTTON);
  static int ultat = HIGH;
  static unsigned long timpapasat = 0;
  static bool tinut = 0;
 Serial.println(butat);
 if(butat == 1 && ultat == 0){
timpapasat= millis();
 }

   if (butat == 0 && ultat == 1 && (millis()-timpapasat)>=2000) {
    tinut = 1;
    if (pagina == 3) Media();
    if (pagina == 4){ onof = !onof;  digitalWrite(MOTOR, LOW);}
  }

  else if (butat == 0 && ultat == 1 && (millis() - timpapasat) < 2000) {
    if (tinut == 0) {
      pagina++;
      pagina = pagina % 5;
      lcd.clear();
    }
  }
    ultat = digitalRead(BUTTON);
} 


