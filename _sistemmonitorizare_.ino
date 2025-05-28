// Biblioteci functii

#include <DHT.h>
#include <SoftwareSerial.h>
#include <EmonLib.h> 
#define VOLT_CAL 400.00 

// Monitorizare tensiune
EnergyMonitor emon1; 
String Data_tensiune;
String Usa_status;
//

// Setari serial
SoftwareSerial mySerial(9,10);  // (Tx,Rx) 
char incomingByte; 
String inputString;
String textMessage;
bool alarmSent = false;
bool usa=false;
bool temp=false;

// Relee
int relay1 = 7;
int relay2 = 6;
int relay3 = 5;
int relay4 = 4;
//

// Senzor Temperatura
#define DHTpin 3             
#define DHTTYPE DHT11        
String Data_SMS;            
String Data_SMS_alarm;
float t,h;                  
DHT dht(DHTpin, DHTTYPE);     
//

//Senzor magnetic usa
int pushButton = 2;
//

void setup() 
{
     emon1.voltage(0, VOLT_CAL, 1.7); //Tensiune: input pin, calibrare..      
      pinMode(pushButton, INPUT_PULLUP);
      pinMode(relay1, OUTPUT);
      digitalWrite(relay1, LOW);
      pinMode(relay2, OUTPUT);
      digitalWrite(relay2, LOW);
      pinMode(relay3, OUTPUT);
      digitalWrite(relay3, LOW);
      pinMode(relay4, OUTPUT);
      digitalWrite(relay4, LOW);
      Serial.begin(9600);
      mySerial.begin(9600); 
      dht.begin();           //Pornesc DHT
      delay(1000);
     while(!mySerial.available()){
        mySerial.println("AT");
        delay(1000); 
        Serial.println("Connecting...");
        }
      Serial.println("Connected!");  
      mySerial.println("AT+CMGF=1");  //Setare SMS in Text Mode 
      delay(1000);  
      mySerial.println("AT+CNMI=1,2,0,0,0");  //Procedura pentru preluare mesaje text 
      delay(1000);
      mySerial.println("AT+CMGL=\"REC UNREAD\""); // Citesc mesaje necitite
     }


//////////////////////////////////////////
void(* resetFunc) (void) = 0;    //functie de salt la inceput cod
////////////////////////////////////////////

void loop()
{  
      alarma();
      //SERIAL
       if(mySerial.available()){
      delay(100);
      // Serial Buffer
      while(mySerial.available()){
        incomingByte = mySerial.read();
        inputString += incomingByte; 
        }
        delay(10);      
        Serial.println(inputString);
        inputString.toUpperCase(); // Schimb caractere mici in mari
        //Control:
        relee();
        temperatura();
        tensiune();
        stare_usa();
        delay(1000);
        //Sterg mesaje si eliberez memoria
      if (inputString.indexOf("OK") == -1){
      mySerial.println("AT+CMGDA=\"DEL ALL\"");
      delay(1000);}
       inputString = "";
  }
}


///////////////////////////////////////////////////////////////////////////////////////////////
    //Functii ce vor fi apelate
   
  void temperatura(){
    //Citire temperatura DHT
        if (inputString.indexOf("TEMPERATURA") > -1)
          {
            mySerial.write("AT+CMGS=\"0775216308\"\r\n");
            delay(1000);
            Data_SMS = "Temperature = "+String(t,1)+" C" + " \nHumidity ="+String(h,1)+ " %";
                                                                                      
            mySerial.print(Data_SMS);
            delay(1000);
            mySerial.write((char)26);
            delay(1000);
            ////Serial.println("SMS sent");
            resetFunc();
          }
  }

void tensiune(){
        
          emon1.calcVI(20,2000);           
          float Voltage   = emon1.Vrms; 
          if (inputString.indexOf("TENSIUNE") > -1)
          {
            mySerial.write("AT+CMGS=\"0723309255\"\r\n");
            delay(1000);
            Data_tensiune="Tensiunea="+String(Voltage, 1)+"V";
            
            mySerial.print(Data_tensiune);
            delay(1000);
            mySerial.write((char)26);
            delay(1000);
            ////Serial.println("SMS sent");
            resetFunc();
          }
   }

   float stare_usa(){
                
          int buttonState = digitalRead(pushButton);
                  
          if (inputString.indexOf("USA") > -1)
          {
            mySerial.write("AT+CMGS=\"0723309255\"\r\n");
            delay(1000);
            Usa_status="Usa="+String(buttonState)+"     1-Deschisa / 0-Inchisa";
             mySerial.print(Usa_status);
            delay(1000);
            mySerial.write((char)26);
            delay(1000);
            ////Serial.println("SMS sent");
            resetFunc();
          }
   }


        
            
//////////////////////////////////////////////////////////////////////////////////////




   void relee(){
  //turn RELAY1 ON or OFF
        if (inputString.indexOf("ON1") > -1)
          {
          digitalWrite(relay1, HIGH);
          delay(100);
            mySerial.write("AT+CMGS=\"0723309255\"\r\n");
            delay(1000);
            mySerial.write("Pornit 1");
            delay(1000);
            mySerial.write((char)26);
            delay(1000);
            ////Serial.println("SMS sent");
          }
         if (inputString.indexOf("OFF1") > -1)
         {
          digitalWrite(relay1, LOW);
          mySerial.write("AT+CMGS=\"0723309255\"\r\n");
          delay(1000);
          mySerial.write("Oprit 1");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          ////Serial.println("SMS sent");
          }          



        //turn RELAY2 ON or OFF
        if (inputString.indexOf("ON2") > -1)
          {
          digitalWrite(relay2, HIGH);
          delay(100);
            mySerial.write("AT+CMGS=\"0723309255\"\r\n");
            delay(1000);
            mySerial.write("Pornit 2");
            delay(1000);
            mySerial.write((char)26);
            delay(1000);
            ////Serial.println("SMS sent");
          }
         if (inputString.indexOf("OFF2") > -1)
         {
          digitalWrite(relay2, LOW);
          mySerial.write("AT+CMGS=\"0723309255\"\r\n");
          delay(1000);
          mySerial.write("Oprit 2");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          ////Serial.println("SMS sent");
          }          



        //turn RELAY3 ON or OFF
        if (inputString.indexOf("ON3") > -1)
          {
          digitalWrite(relay3, HIGH);
          delay(100);
            mySerial.write("AT+CMGS=\"0723309255\"\r\n");
            delay(1000);
            mySerial.write("Pornit 3");
            delay(1000);
            mySerial.write((char)26);
            delay(1000);
            ////Serial.println("SMS sent");
          }
         if (inputString.indexOf("OFF3") > -1)
         {
          digitalWrite(relay3, LOW);
          mySerial.write("AT+CMGS=\"0723309255\"\r\n");
          delay(1000);
          mySerial.write("Oprit 3");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          ////Serial.println("SMS sent");
          }          



        //turn RELAY4 ON or OFF
        if (inputString.indexOf("ON4") > -1)
          {
          digitalWrite(relay4, HIGH);
          delay(100);
            mySerial.write("AT+CMGS=\"0723309255\"\r\n");
            delay(1000);
            mySerial.write("Pornit 4");
            delay(1000);
            mySerial.write((char)26);
            delay(1000);
            ////Serial.println("SMS sent");
          }
         if (inputString.indexOf("OFF4") > -1)
         {
          digitalWrite(relay4, LOW);
          mySerial.write("AT+CMGS=\"0723309255\"\r\n");
          delay(1000);
          mySerial.write("Oprit 4");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          ////Serial.println("SMS sent");
          }          
}

    
  ///////////////////////////////////////////////////////////////////////////////
 void tensiune_down(){
  Serial.print( "-Tensiune DOWN" );
  mySerial.println("AT+CMGF=1");    //Setează modulul GSM pentru text
  delay(10);  
  mySerial.println("AT+CMGS=\"0723309255\"\r"); 
  delay(10);
  mySerial.println("Atentie!! Tensiune DOWN");
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(10);
  mySerial.println("AT+CMGD=2");
}
void tensiune_up()
{
  Serial.print( "-Tensiune UP" );
  mySerial.println("AT+CMGF=1");    //Setează modulul GSM pentru text
  delay(10);  
  mySerial.println("AT+CMGS=\"0723309255\"\r");
  delay(10);
  mySerial.println("Revenire tensiune");
  //mySerial.println(String("Tensiune citita : ") +current_Volts+ String("V"));
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(10);
  mySerial.println("AT+CMGD=2");
  }


void usa_deschisa(){
  Serial.print( "-Usa Deschisa" );
  mySerial.println("AT+CMGF=1");    //Setează modulul GSM pentru text
  delay(10);  
  mySerial.println("AT+CMGS=\"0723309255\"\r");
  delay(10);
  mySerial.println("Atentie!! Usa DESCHISA");
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(10);
  mySerial.println("AT+CMGD=2");
}
void usa_inchisa()
{
  Serial.print( "-Usa Inchisa" );
  mySerial.println("AT+CMGF=1");    //Setează modulul GSM pentru text
  delay(10);  
  mySerial.println("AT+CMGS=\"0723309255\"\r");
  delay(10);
  mySerial.println("USA INCHISA");
  //mySerial.println(String("Tensiune citita : ") +current_Volts+ String("V"));
  mySerial.println((char)26);// ASCII pentru CTRL+Z
  delay(10);
  mySerial.println("AT+CMGD=2");
  
}


void temp_mare(){

  Serial.print( "-Temperatura ridicata" );
  mySerial.println("AT+CMGF=1");    //Setează modulul GSM pentru text
  delay(10);  
  mySerial.println("AT+CMGS=\"0723309255\"\r"); 
  delay(10);
  mySerial.println("Atentie!! Temperatura ridicata");
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(10);
  mySerial.println("AT+CMGD=2");

}
void temp_normala()
{
  Serial.print( "-Temperatura normala" );
  mySerial.println("AT+CMGF=1");    //Setează modulul GSM pentru text
  delay(10);  
  mySerial.println("AT+CMGS=\"0723309255\"\r");
  delay(10);
  mySerial.println("TEMPERATURA NORMALA");
  //mySerial.println(String("Tensiune citita : ") +current_Volts+ String("V"));
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(10);
  mySerial.println("AT+CMGD=2");   
}
    
  void alarma(){      
     
  int buttonState = digitalRead(pushButton);
  
  t = dht.readTemperature();
  h = dht.readHumidity();
  
  emon1.calcVI(20,2000);           
  float Voltage   = emon1.Vrms; 

        if (Voltage <200)
              
        {
        if (alarmSent==false)
        {
          tensiune_down();
          alarmSent = true;
        }
        }
        
      else if(Voltage>200){                             
        if (alarmSent==true){                  
          tensiune_up();          
          alarmSent = false;             
            }
       }
       if(buttonState==1){                             
        if (usa==false){                  
          usa_deschisa();          
          usa = true;             
          }
       }                   
        else if(buttonState==0){                             
        if (usa==true){                  
          usa_inchisa();          
          usa = false;             
          }
       }
  
     if(t>=27){                             
        if (temp==false){                  
          temp_mare();          
          temp=true;
        }
       }                   
     else if(t<=25){                            
        if (temp==true){                  
          temp_normala();          
          temp=false;
        }
       }
  
  }
