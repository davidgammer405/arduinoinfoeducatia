/**
 * Realizează procesul de setup pentru calibrarea udării solului.
 *
 * Această funcție ghidează utilizatorul printr-un proces de calibrare a senzorului de umiditate,
 * folosind un LCD pentru afișarea instrucțiunilor și un buton pentru confirmare.
 * 
 * Procesul implică două etape:
 * 1. Calibrarea pentru sol uscat: utilizatorul este instruit să plaseze senzorul în sol uscat și să apese butonul.
 *    Se realizează 500 de citiri pentru a calcula media valorii de umiditate în sol uscat.
 * 2. Calibrarea pentru sol umed: utilizatorul este instruit să plaseze senzorul în sol umed și să apese butonul.
 *    Se realizează 500 de citiri pentru a calcula media valorii de umiditate în sol umed.
 * 
 * La final, funcția setează variabilele globale relevante și returnează valoarea medie dintre cele două măsurători,
 * care poate fi folosită ca prag pentru udarea automată.
 *
 * Returneaza int Valoarea medie dintre umiditatea măsurată în sol uscat și cea din sol umed.
 */
int Media() // Functia pentru realizarea setup-ului de udare
{
  // Mesaj de început
  lcd.clear();
  lcd.print("Incepe setupul");
  delay(3000);

  // Calibrare sol uscat
  lcd.clear();
  lcd.print("Pune in mediu");
  lcd.setCursor(0, 1);
  lcd.print("uscat si apasa");
  while (digitalRead(BUTTON) == HIGH) {} // Așteaptă apăsarea butonului
  delay(500); // Debounce
  while (digitalRead(BUTTON) == LOW) {}  // Așteaptă eliberarea butonului

  lcd.clear();
  lcd.print("Se seteaza...");
  bot = 0;
  for (int i = 0; i < 500; i++) {
    bot += udapa(); // Citire umiditate sol uscat
  }
  bot /= 500; // Media sol uscat

  lcd.clear();
  lcd.print("Uscat setat");
  delay(2000);

  // Calibrare sol umed
  lcd.clear();
  lcd.print("Pamant ud");
  lcd.setCursor(0, 1);
  lcd.print("apasa pe buton");
  while (digitalRead(BUTTON) == HIGH) {} // Așteaptă apăsarea butonului
  delay(500); // Debounce
  while (digitalRead(BUTTON) == LOW) {}  // Așteaptă eliberarea butonului

  lcd.clear();
  lcd.print("Se seteaza...");
  top = 0;
  for (int i = 0; i < 500; i++) {
    top += udapa(); // Citire umiditate sol umed
  }
  top /= 500; // Media sol umed

  // Finalizare setup
  lcd.clear();
  lcd.print("Setup completat");
  delay(2000);
  lcd.clear();

  setupled = true; // Setup realizat
  apauda = (bot + top) / 2; // Prag udare
onof = 1;
  return apauda; // Returnează pragul de udare
}
