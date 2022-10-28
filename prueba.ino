int humedad = 0;
int porcentaje = 0;

const int pin = 9;

#define pinLED 12

void setup(){ 

  pinMode(pinLED, OUTPUT);
  
  Serial.begin(9600); // serial monitor baud rate
  pinMode(A0, INPUT); // PinMode set, pin for moisture sensor

  pinMode(pin, OUTPUT);
}

void loop(){

  int v = analogRead(A0);
  if (v <= 3){
    digitalWrite(pinLED, HIGH); 
  }
  else{
    digitalWrite(pinLED, LOW);
  }
  Serial.print("Luz");
  Serial.println(v);
  
  humedad = analogRead(A0); // reading value 
  porcentaje = map(humedad, 0, 1023, 0, 100); // changing to percent
  Serial.print("humedad= ");
  Serial.print(porcentaje); // Print porcentage
  Serial.println("%");
  if(porcentaje > 10){
     digitalWrite(pin, HIGH);   // encendemos el rele osea la bomba
  }
  else{
    digitalWrite(pin, LOW);    // apagamos la bomba 
  }
  delay(1000);
}
 
