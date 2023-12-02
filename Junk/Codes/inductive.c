int inductive_pin = 4;
int inductive;

void setup()
{
	Serial.begin(9600);
	pinMode(inductive_pin,INPUT);
}

void loop()
{
	inductive=digitalRead(inductive_pin);

	if(inductive==LOW)
	{
		Serial.println("Metal detected");
		delay(500);
	}

	else
	{
		Serial.println("No Metal");
		delay(500);
	}

}