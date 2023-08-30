// C++ code in the Arduino UNO IDE
// Soil Moisture Detector!
int max;
int red;
int yellow;
int green;
int blue;
float timer;
void buzz(float time);

void setup()
{
	pinMode(A0, INPUT);
	Serial.begin(9600);
	pinMode(12, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(3, OUTPUT);

	max = 1024;  // maximum reading (in this case, 100% dry)
	red = 1000;  // 75% dry
	yellow = 650;  // 50% dry
	green = 400;  // 25% dry
	blue = 0;  // 0% dry

	timer = 0;
}

void loop()
{
	Serial.print(analogRead(A0));
	Serial.print("; ");
	Serial.println(timer);

	// RED light + buzzer
	if ((analogRead(A0) >= red) && (analogRead(A0) < max))
	{
		digitalWrite(12, HIGH);
		buzz(timer);
	}
	else {
		digitalWrite(12, LOW);
	}

	// YELLOW light 
	if ((analogRead(A0) >= yellow) && (analogRead(A0) < yellow))
	{
		digitalWrite(8, HIGH);
	}
	else {
		digitalWrite(8, LOW);
	}

	// GREEN light 
	if ((analogRead(A0) >= green) && (analogRead(A0) < green))
	{
		digitalWrite(7, HIGH);
	}
	else {
		digitalWrite(7, LOW);
	}

	// BLUE light 
	if ((analogRead(A0) >= blue) && (analogRead(A0) < blue))
	{
		digitalWrite(4, HIGH);
	}
	else {
		digitalWrite(4, LOW);
	}

	delay(10); // Delay a little bit to improve simulation performace
	buzz(0.0); // silences the buzzer if it wasn't previously silenced
	timer += 0.01;
}

void buzz(float time)
{
	if (time > floor(time) + 0.5)
	{
		tone(3, 100);
	}
	else {
		noTone(3);
	}
}