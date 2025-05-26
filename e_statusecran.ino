void pagini(int pag){

switch(pag){
case 0:
int moistureper;
lcd.setCursor(0, 0);
lcd.print("Moisture %");
map(moistureper,bot,top,0,100);
lcd.setCursor(0, 1);
lcd.print(moistureper);
lcd.setCursor(3, 1);
lcd.print("%");
break;
case 1:
lcd.setCursor(0, 0);
lcd.print("Media de udare:");
lcd.setCursor(0, 1);
lcd.print(apauda);
break;
case 2:
lcd.setCursor(0, 0);
lcd.print("Status:");
lcd.setCursor(0, 1);
if(apauda<moisture)
lcd.print("Se uda planta..");
else
lcd.print("Umiditate buna:)");
break;
case 3:
lcd.setCursor(0, 0);
lcd.print("Tine apasat");
lcd.setCursor(0, 1);
lcd.print("pentru setup");
break;
case 4:
lcd.setCursor(0, 0);
lcd.print("ON/OFF udat auto");
lcd.setCursor(0, 1);
lcd.print("tine apasat");
break;
}
}