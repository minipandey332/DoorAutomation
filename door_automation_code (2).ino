
void setup() {
  // initialize digital pin  as an  input,an output.
  //output signal coming from arduino to motor driver 
  pinMode(6,OUTPUT );
  pinMode(7,OUTPUT );
  // input signal coming from ir sensor to arduino 
  pinMode(5, INPUT);
  pinMode(4, INPUT);
}

// the loop function runs over and over again forever
void loop() 
{
  if(digitalRead(4)==LOW && digitalRead(5)==LOW)//In this case gate will be in open mode(both sensor detect on same time)
  {
  digitalWrite(13,HIGH); 
  digitalWrite(6, HIGH); 
  digitalWrite(7, LOW);
  }
else//In this case also gate will be in open mode (1 sensor detect at a time)
 {
  if( digitalRead(4)==LOW && digitalRead(5)==HIGH)//gate open when person enter in the room
  {
  digitalWrite(13,HIGH); 
  digitalWrite(6, HIGH); 
  digitalWrite(7, LOW);
   delay(2000); 
  }
  else if(digitalRead(5)==LOW && digitalRead(4)==HIGH)//gate open when person coming out from room
  {
   digitalWrite(13,HIGH);
   digitalWrite(6, HIGH); 
   digitalWrite(7, LOW);
   delay(2000);
  }   
   
 }
 if(digitalRead(4)==HIGH && digitalRead(5)==HIGH)//This is the case for gate remain in close mode
 {
  digitalWrite(13,LOW);
  digitalWrite(6, LOW);
  digitalWrite(7,HIGH);                
 }
}
