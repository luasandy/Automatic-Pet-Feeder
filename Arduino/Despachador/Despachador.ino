int led = 13;
  void setup () {
   pinMode(led, OUTPUT); //LED 13 como salida
   Serial.begin(9600); //Inicializo el puerto serial a 9600 baudios

}

void loop() {
  if (Serial.available()) { //Si está disponible
      char c = Serial.read(); //Guardamos la lectura en una variable char
      if (c == '1') { //Si recibe 1 significa que sera una porcion Chica
         digitalWrite(led, HIGH);
         delay(1000);
         digitalWrite(led, LOW); //se apaga el led
      } else if (c == '2') { //Si es 2 significa que sera una porcion Mediana
         digitalWrite(led, HIGH);
         Serial.print("8");   //mandar por serial debug
         delay(2000);
         digitalWrite(led, LOW); //se apaga el led
      } else if (c == '3') { //Si es 2 significa que sera una porcion Mediana
         digitalWrite(led, HIGH);
         Serial.print("9");   //mandar por serial debug
         delay(3000);
         digitalWrite(led, LOW); //se apaga el led
      } else{
        digitalWrite(led, LOW); //se apaga el led
      }      
   }
}
