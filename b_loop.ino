/*Funcția principală de loop pentru schița Arduino.
 *
 * Această funcție este apelată repetat de către runtime-ul Arduino. Ea realizează următoarele:
 * - Inițializează valorile de prag pentru top, bottom și punctul de udare.
 * - Citește valoarea curentă a umidității solului de la senzor.
 * - Dacă udarea automată este activată (`onof == 1`), pornește rutina de udare automată.
 * - Gestionează evenimentele de apăsare a butonului.
 * - Actualizează afișajul LCD cu pagina curentă.
 * - Dacă setup-ul pentru udare nu a fost finalizat și utilizatorul se află pe pagina de setup,
 *   calculează valoarea medie pentru udare, finalizează setup-ul și revine la pagina principală.
 */
void loop()
{
  top = 250;
  bot = 700;
  apauda = 475;
  moisture = udapa();// Citirea umidității de la senzor

  if (onof == 1)// Dacă udarea automată este activată
    udatauto();
  apasbuton();

  pagini(pagina);// Afișarea paginii curente pe LCD
  if (setupled == false && pagina == 3) // Dacă nu s-a realizat setup-ul și suntem pe pagina de setup
  {
    apauda = Media(); // Realizarea setup-ului pentru udare
    pagina = 0; // Revenirea la pagina principală
  } 
}