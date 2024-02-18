
String readString;

void setup()
{
  Serial.begin(9600);           //Set rate for communicating with phone
  pinMode(6, OUTPUT); //go output signal_1 into motor driver  
  pinMode(7, OUTPUT);//go output signal_2 into motor driver  
  pinMode(LED_BUILTIN, OUTPUT); 
//  initially set Door in closed mode     
  digitalWrite(LED_BUILTIN,LOW);
  digitalWrite(6, LOW);
  digitalWrite(7,HIGH);
}
void loop()
{
  while(Serial.available())    //Check if there are available bytes to read
  {
    delay(10);                 //Delay to make it stable
    char c = Serial.read();    //Conduct a serial read
    if (c == '#'){
      break;                   //Stop the loop once # is detected after a word
    }
    readString += c;                //Means readString = readString + c
  }
    if (readString.length() >0)
    {
      Serial.println(readString);
                  
     if(readString == "f success"){// for door open (if fingerprint detect correct door will open for 2 second and then closed automatically
      Serial.print(readString);
      digitalWrite(LED_BUILTIN,HIGH);
      digitalWrite(6, HIGH); 
      digitalWrite(7, LOW);
      delay(2000); 
      digitalWrite(LED_BUILTIN,LOW);
      digitalWrite(6, LOW);
      digitalWrite(7,HIGH);
      }
    else if(readString=="f failed")// for door remain closed if fingerprint detect wrong person
      {
        Serial.print(readString);
        digitalWrite(LED_BUILTIN,LOW);
        digitalWrite(6, LOW);
        digitalWrite(7,HIGH); 
      }
      readString="";
    }
}
