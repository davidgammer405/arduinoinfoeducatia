/**
 * Controlează sistemul de udare automată pe baza umidității solului.
 *
 * Această funcție realizează următoarele acțiuni:
 * - Stinge atât LED-ul verde, cât și pe cel roșu.
 * - Activează pompa de apă (motorul) dacă umiditatea solului depășește media de udare .
 * - Aprinde LED-ul verde dacă udarea este activă, sau LED-ul roșu dacă nu este.
 */
void udatauto() // Functia pentru udarea automată
{
  digitalWrite(GREEN_LED, LOW); // Stinge LED-ul verde
  digitalWrite(RED_LED, LOW);   // Stinge LED-ul roșu

  // Pornește motorul dacă umiditatea este mai mare decât pragul de udare
  digitalWrite(MOTOR, moisture > apauda ? HIGH : LOW);

  // Aprinde LED-ul corespunzător stării de udare
  digitalWrite(moisture > apauda ? GREEN_LED : RED_LED, HIGH);
}