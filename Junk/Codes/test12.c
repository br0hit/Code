#include <Stepper.h>
  #include <Servo.h>

  int stepsPerRevolution= 2048;  // number of steps motor will take in one revolution (constant)
  int motSpeed=10;  //speed of motor in rpm
  int dt=500; //in ms
  Stepper myStepper(stepsPerRevolution,9,11,10,12);

  Servo flaptop,flapbottom;
  int pos=0;   // We use pos to define the position of the servo at any point during its motion using Servo.Write(pos)

  int rain_pin=3;
  int rain;   // We are using a Ananlog pin for the Rain Sensor to get a much better and acuurate result as compared to a digital sensor

  int inductive_pin = 2;
  int inductive;   // The inductive pin is connected to a digital pin and it gives a value of low when no metal is placed and high when a metal is near it

  int count=0;


  void setup()
  {
    Serial.begin(9600);  // Initializing the Serial monitor to see the digitalized output in each case

    myStepper.setSpeed(motSpeed);
    flaptop.attach(13);  // flap is like servo whereever it is used
    flapbottom.attach(3);


    pinMode(rain_pin,INPUT);  // pinMode(3,INPUT) , Connecting Rain Sensor to the Analog pin number 4 of the arduino and intializing it
    pinMode(inductive_pin,INPUT);  // pinMode(4,INPUT)  , Connecting the Inductive sensor to the digital pin number 4 and initilizing it


  }

  void loop()
  {
    // Read 

    // Case 1: If it is wet waste: 


    if(count==0)  // If there is water then the resistance of the metal will decrese and so will the reading 
    {
      // First the top flap will open up for the waste to fall in the second bin 


      delay(5000);

       //     for (pos = 0; pos <= 90; pos += 5) {    // Servo.write defines the angle position of the servo
       //  flaptop.write(pos);              
       //  delay(10);   // whenever u see time variables in arduino ? delay(time)  the time is in ms                   
       // } 

      flaptop.write(180);
      flaptop.write(0);
      delay(5000);
      
      

       // delay(1000);

       // // Closing of the top flap

       //  for (pos = 180; pos >= 0; pos -= 5) { 
       //  flaptop.write(pos);              
       //  delay(10); }

        delay(1000);

        // Then the bottom bin will go directly below the bin in which the waste is to be recycled 

      myStepper.step(stepsPerRevolution/6);  //the number given in bracket is number of steps it will take
      delay(dt);
      myStepper.step(-stepsPerRevolution/6); // '+' in forward and '-' in backward rotation
      delay(dt); 


      delay(2000);

      // Once it is exaclty below it the bottom flap will open and the waste will fall down

    count++;

  }
         delay(5000);

 
      flapbottom.write(180);
      delay
      flapbottom.write(0);



      }