int X,Y;

unsigned long timer = 0;

String inputString = "";         
bool stringComplete = false; 

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if(Serial2.available() > 0)
  {
//    uint16_t data = 0;
//    data = Serial2.read();
//    data |= Serial2.read() << 8;
//    char inChar = (char)data;
    char inChar = (char)Serial2.read();
    digitalWrite(LED_BUILTIN,HIGH);
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
  if (stringComplete) 
  {
    if(inputString.startsWith("x"))
    {
//     Serial.print("X:");
     inputString.replace("x","");
     X=inputString.toInt();
//     Serial.println(X);
     inputString = "";
     stringComplete = false;
    }
  else if(inputString.startsWith("y"))
    {
//     Serial.print("Y:");
     inputString.replace("y","");
     Y=inputString.toInt();   // Y
//     Serial.println(Y);
     inputString = "";
     stringComplete = false;
    }
  }
    if (millis() - timer > 50) 
  {
    Serial.print("X = "); Serial.print(X); Serial.print("\t");
    Serial.print("Y = "); Serial.println(Y);
    timer = millis();
  }

}
