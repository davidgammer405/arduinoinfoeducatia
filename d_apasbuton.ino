/**
 * Gestionează logica de apăsare a butonului pentru diferite moduri de operare.
 *
 * Această funcție citește starea unui buton și execută acțiuni în funcție de cât timp este apăsat
 * și de pagina curentă (`pagina`). Distinge între apăsare scurtă și lungă și execută comportamente
 * diferite în funcție de modul activ:
 * 
 * Funcția folosește variabile statice pentru a urmări starea anterioară a butonului, durata apăsării și dacă butonul
 * este ținut apăsat. De asemenea, gestionează debouncing-ul și tranzițiile de stare.
 */
void apasbuton() // Functia pentru apasarea butonului
{
  int butat = digitalRead(BUTTON);             // Citirea stării butonului
  static int ultat = HIGH;                     // Variabila pentru starea anterioară a butonului
  static unsigned long timpapasat = 0;         // Timpul de apăsare a butonului
  static bool tinut = 0;                       // Variabila pentru a verifica dacă butonul este ținut apăsat

  if (butat == 1 && ultat == 0)
  {
    timpapasat = millis();
  } // Dacă butonul este apăsat și starea anterioară era LOW, se salvează timpul curent

  if (ultat == 1 && (millis() - timpapasat) >= 1000 && tinut == 0)
  {
    tinut = 1;
    if (pagina == 3)
      Media(); // Dacă butonul a fost ținut apăsat mai mult de 1 secundă și nu era deja ținut, se realizează setup-ul pentru udare
    if (pagina == 4)
    {
      onof = !onof;
      digitalWrite(MOTOR, LOW);
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    } // Dacă butonul a fost ținut apăsat mai mult de 1 secundă și nu era deja ținut, se schimbă starea ON/OFF pentru udare automată
  } // Dacă butonul a fost ținut apăsat mai mult de 1 secundă și nu era deja ținut, se schimbă starea

  if (pagina == 5)
  {
    if (butat == 1 && ((millis() - timpapasat) >= 750))
    {
      tinut = 1;
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      digitalWrite(MOTOR, HIGH);
    }
    if (butat == 0 && ultat == 1)
      digitalWrite(MOTOR, LOW);
  } // Dacă suntem pe pagina de udare manuală și butonul este apăsat mai mult de 750 ms, se pornește motorul și se aprinde LED-ul verde

  if (butat == 0 && ultat == 1 && (millis() - timpapasat) < 1000)
  {
    if (tinut == 0)
    {
      pagina++;
      pagina = pagina % 6;
      lcd.clear();
    }
  } // Dacă butonul a fost eliberat și starea anterioară era HIGH, se schimbă pagina curentă dacă butonul nu a fost ținut apăsat mai mult de 1 secundă

  ultat = digitalRead(BUTTON); // Actualizarea stării anterioare a butonului
  if (ultat == 0)              // Dacă butonul este eliberat se resetază timpul de apăsare și variabila pentru a verifica dacă butonul este ținut apăsat
    tinut = 0;
}
