void loop() {
  
 // if (!setupled) {
   // apauda = Media();
  //}

  


  moisture = udapa();
  if(millis()%1000==0){
  Serial.print("Cat de uda e apa: ");
  Serial.println(moisture);}

 if(onof) udatauto();
  apasbuton();

pagini(pagina);
}