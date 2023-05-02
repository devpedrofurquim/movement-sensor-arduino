// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(11, INPUT_PULLUP);  
  

}

void loop()
{
  digitalWrite(7, LOW);
  delayMicroseconds(2); 
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  
   long time = pulseIn(6, HIGH);
   float distancia = time * 0.0001 * 340 /2;
  
   if(distancia > 50){
     digitalWrite(9, HIGH);
     digitalWrite(8, HIGH);
     digitalWrite(5, LOW);
     digitalWrite(4, LOW);
     digitalWrite(3, LOW);
     digitalWrite(2, LOW);
  }else if (distancia >= 30 && distancia <= 50){
     digitalWrite(5, HIGH);
     digitalWrite(4, HIGH);
     digitalWrite(9, LOW);
     digitalWrite(8, LOW);
     digitalWrite(2, LOW);
     tone(11, 500);
     delay(500);
     noTone(11);
     delay(100);
     digitalWrite(5, LOW);
     digitalWrite(4, LOW);
     delay(100);
  }else{
     digitalWrite(3, HIGH);
     digitalWrite(2, HIGH);
     digitalWrite(5, LOW);
     digitalWrite(4, LOW);
     digitalWrite(9, LOW);
     digitalWrite(8, LOW);
     tone(11, 1000);
     delay(500);
     noTone(11);
     delay(100);
     digitalWrite(3, LOW);
     digitalWrite(2, LOW);
     delay(100);
  }
     
   Serial.println(distancia);
  
}
