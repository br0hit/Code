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
    flaptop.attach(2);  // flap is like servo whereever it is used
    flapbottom.attach(3);


    pinMode(rain_pin,INPUT);  // pinMode(3,INPUT) , Connecting Rain Sensor to the Analog pin number 4 of the arduino and intializing it
    pinMode(inductive_pin,INPUT);  // pinMode(4,INPUT)  , Connecting the Inductive sensor to the digital pin number 4 and initilizing it


  }

  void loop()
  {
    // Read 

    // Case 1: If it is wet waste: 


  delay(5000);

   flaptop.write(0);
    	    delay(2000);
    	flapbottom.write(0);
    	delay(3000);

    	for(pos=0;pos<180;pos+=1)
    	{
    		flaptop.write(pos);
    		delay(1);
    	}
      flaptop.write(0);
    	delay(2000);
     

      myStepper.step(-stepsPerRevolution/6);  //the number given in bracket is number of steps it will take
      delay(dt);
      delay(3000);
          	for(pos=0;pos<180;pos+=1)
    	{
    		flapbottom.write(pos);
    		delay(5);
    	}
      delay(2000);
      flapbottom.write(0);
      delay(2000);
      myStepper.step(+stepsPerRevolution/6); // '+' in forward and '-' in backward rotation
      delay(dt); 
      delay(2000);

   delay(100000);





      }