Servo myservo;

int ledPin = 12;                
int pirPin = 13;                 
int pirStat = 0;                   
int pos = 0;

void setup() { pinMode(ledPin, OUTPUT);     
 pinMode(pirPin, INPUT);
 myservo.attach(9); 
 Serial.begin(9600);
 myservo.write(pos); 
}

void loop(){
 
  pirStat = digitalRead(pirPin); 
  if (pirStat == HIGH){            
   
   Serial.println("Motion Detected");

   for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(20);                       
   } 
    for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(20);                       
   }
 } 
 else {
   
 }
}  