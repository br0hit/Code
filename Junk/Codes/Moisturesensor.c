int rain_pin=3;
int rain;

void setup()
{
	Serial.begin(9600);  

	pinMode(rain_pin,INPUT);
}

void loop()
{
	int rain;

	rain=analogRead(A0);

	serial.println("GOd I hope this thing works: ");
	Serial.println(rain);

	delay(2000);
}