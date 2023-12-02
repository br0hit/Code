#include <Servo.h>
Servo myservo;
             
                   
int pos = 0;

void setup()
{


 myservo.attach(9); 
 Serial.begin(9600);
 myservo.write(pos); 

}

void loop(){
 
  

   for (pos = 0; pos <= 180; pos += 1)
    { 
     myservo.write(pos);              
     delay(20);                       
   } 

   delay(5000);



    for (pos = 180; pos >= 0; pos -= 1)
     { 
    myservo.write(pos);              
     delay(20);  

                          
     }
 } 
  