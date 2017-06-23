/* Declaramos las variables */
long distancia;
long tiempo;
int estado=0; //bandera que indica estado 
int actual=1; //bandera que indica si hay comida
int avisar=0;  //bandera que indica si envio senial de comida


void setup(){
Serial.begin(9600);
pinMode(9, OUTPUT);     //Declaramos el pin 9 como salida del pulso ultrasonico trig
pinMode(8, INPUT);      //Declaramos el pin 8 como entrasa (tiempo que tarda en volver) echo
pinMode(12, OUTPUT);    //led senial de comida
pinMode(2, INPUT);      //act1 seniales que vendran de RP
pinMode(3, INPUT);      //act2 seniales que vendran de RP
pinMode(4, OUTPUT);     //motor1

}

void loop(){
    int act1, act2;
    act1 = digitalRead(2);
    act2 = digitalRead(3);
	
	if (Serial.available()) { //Si está disponible el serial
		char c = Serial.read(); //Guardamos la lectura en una variable char
		if (c == '1') { //Si recibe 1 significa que sera una porcion Chica
			digitalWrite (4, HIGH); //apaga motor
			delay(2000);
			digitalWrite (4, LOW); //apaga motor
		} else if (c == '2') { //Si es 2 significa que sera una porcion Mediana
			digitalWrite (4, HIGH); //apaga motor
			delay(4000);
			digitalWrite (4, LOW); //apaga motor
		} else if (c == '3') { //Si es 3 significa que sera una porcion Grande
			digitalWrite (4, HIGH); //apaga motor
			delay(6000);
			digitalWrite (4, LOW); //apaga motor
		} else{
			digitalWrite(4, LOW); //se apaga el led
		}      
	}
	
    
    /* Se estabiliza el sensor */
    digitalWrite(9,LOW);
    delayMicroseconds(5);
    /* Se envia el pulso ultrasonico */
    digitalWrite(9, HIGH);
    delayMicroseconds(10);
    /* Mide el tiempo transcurrido entre la salida y la llegada del pulso ultrasonico */
    tiempo=pulseIn(8, HIGH);
    /* Se calcula la distancia on esta formila*/
    distancia= int(0.017*tiempo);
    /* Se imprime la distancia en centimetros en el monitor serial */
    //Serial.println("Distancia ");
    //Serial.println(distancia);
    //Serial.println(" cm");
    delay(5);
	
	if((actual == 1) && (avisar == 0)){estado = 0;}
	if((actual == 0) && (avisar == 0)){estado = 1;}
	if((actual == 0) && (avisar == 1)){estado = 2;}
	
	switch(estado){
		0: 
			if(distancia > 20){ //hay poca comida
				actual=0;
				avisar=0;
			}else{
				actual=1;
				avisar=0;
			}
			break;
		
		1: 
			if(distancia > 20){
				actual=0;
				avisar=1;
				Serial.print("9");   //mandar senial a la raspberry para indicar que hay poca comida
			}else{
				actual=1;
				avisar=0;
			}
			break;
		2: 
			if(distancia <= 20){
				actual=1;
				avisar=0;
				Serial.print("8");   //mandar senial a la raspberry 8= ya hay comida
			}else{
				actual=0;
				avisar=1;
			}
			break;
		
	}
	
	/*
    if ((distancia > 20)){
		digitalWrite (12, HIGH); //senaial de comida
		Serial.print("9");   //mandar senial a la raspberry para indicar que hay poca comida
        delay(1000);
        digitalWrite (12, LOW);
    }
	*/
      
}

