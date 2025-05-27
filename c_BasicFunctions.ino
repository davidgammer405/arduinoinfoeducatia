int udapa()// Functia pentru citirea umidității de la senzor
{
  return analogRead(SENSOR_PIN);// Citirea valorii de la senzorul de umiditate
}
