/**
 * Afiseaza diferite pagini de informatii pe LCD in functie de numarul paginii curente.
 *
 * Pagini:
 *   - Pagina 0: Afiseaza procentul actual de umiditate din sol, actualizat la fiecare 500ms.
 *   - Pagina 1: Afiseaza valoarea medie de udare.
 *   - Pagina 2: Afiseaza statusul sistemului, inclusiv starea auto-udarii si conditia de umiditate.
 *   - Pagina 3: Instructiuni pentru intrarea in modul setup.
 *   - Pagina 4: Instructiuni pentru activarea/dezactivarea auto-udarii.
 *   - Pagina 5: Instructiuni pentru udare manuala.
 */
void pagini(int pag) {
    static unsigned long curentsecs = 0;

    switch (pag) {
        case 0: // Pagina 0 - Afiseaza procentul de umiditate din sol
            lcd.setCursor(0, 0);
            lcd.print("Moisture %");
            // Actualizeaza valoarea la fiecare 500ms
            if ((millis() - curentsecs) >= 500) {
                lcd.clear();
                curentsecs = millis();
                moistureper = map(moisture, top, bot, 0, 100);
                moistureper = constrain(moistureper, 0, 100);
                moistureper = 100 - moistureper;
            }
            lcd.setCursor(0, 1);
            lcd.print(moistureper);
            lcd.setCursor(3, 1);
            lcd.print("%");
            break;

        case 1: // Pagina 1 - Afiseaza media de udare
            lcd.setCursor(0, 0);
            lcd.print("Media de udare:");
            lcd.setCursor(0, 1);
            lcd.print(apauda);
            break;

        case 2: // Pagina 2 - Afiseaza statusul sistemului
            lcd.setCursor(0, 0);
            lcd.print("Status:");
            lcd.setCursor(0, 1);
            if (onof == 0) {
                lcd.print("Oprit");
            } else {
                if (apauda < moisture)
                    lcd.print("Se uda planta..");
                else
                    lcd.print("Umiditate buna:)");
            }
            break;

        case 3: // Pagina 3 - Instructiuni pentru setup
            lcd.setCursor(0, 0);
            lcd.print("Tine apasat");
            lcd.setCursor(0, 1);
            lcd.print("pentru setup");
            break;

        case 4: // Pagina 4 - Instructiuni ON/OFF auto-udare
            lcd.setCursor(0, 0);
            lcd.print("ON/OFF udat auto");
            lcd.setCursor(0, 1);
            lcd.print("tine apasat");
            break;

        case 5: // Pagina 5 - Instructiuni pentru udare manuala
            lcd.setCursor(0, 0);
            lcd.print("Tine apasat");
            lcd.setCursor(0, 1);
            lcd.print("pentru udare");
            break;
    }
}
