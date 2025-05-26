void udatauto()
 {
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(MOTOR, moisture>apauda ? HIGH : LOW);
  digitalWrite(moisture>apauda ? GREEN_LED : RED_LED, moisture>apauda ? HIGH : LOW);
  
}