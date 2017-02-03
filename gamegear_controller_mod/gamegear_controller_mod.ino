/*
  Read a Genesis controller for U/D/L/R/S/B/C and output U/D/L/R/S/1/2
  for use in a port in a modded Game Gear.
  - btrim 2015
*/


typedef enum buttons_ {
  // Input Pins
  buttonUp = 2,
  buttonDown,
  buttonLeft,
  buttonRight,
  buttonOne,
  buttonTwo,
  // Output pins
  SELECT,
  buttonOutStart = 13, // LED pin is 13, so it should go off when start is pressed
  buttonOutUp = A5,
  buttonOutDown = A4,
  buttonOutLeft = A3,
  buttonOutRight = A2,
  buttonOutOne = A1,
  buttonOutTwo = A0

}
button;

void setup()
{
  for ( short btn = buttonUp; btn <= buttonTwo; ++btn )
  {
    pinMode(btn, INPUT_PULLUP);
    digitalWrite(btn, HIGH); //Enable the pull-up resistor
  }

  short outBtn[] = { SELECT, buttonOutStart, buttonOutUp, buttonOutDown, buttonOutLeft, buttonOutRight, buttonOutOne, buttonOutTwo }; 
  for ( short i = 0; i < 8; i++)//SELECT; btn <= buttonOutTwo; ++btn )
  {
    pinMode(outBtn[i], OUTPUT);
    digitalWrite(outBtn[i], HIGH);
  }
}

void readPins()
{
  digitalWrite(SELECT, HIGH);
  delayMicroseconds(20);

  short up = digitalRead(buttonUp);
  short down = digitalRead(buttonDown);
  short left = digitalRead(buttonLeft);
  short right = digitalRead(buttonRight);
  short one = digitalRead(buttonOne);
  short two = digitalRead(buttonTwo);

  digitalWrite( buttonOutUp, up);
  digitalWrite( buttonOutDown, down);
  digitalWrite( buttonOutLeft, left);
  digitalWrite( buttonOutRight, right);
  digitalWrite( buttonOutOne, one);
  digitalWrite( buttonOutTwo, two);

  // Since start is multiplexed with C, select needs to be set low
  // this tells the controller to report start/A instead of C/B
  digitalWrite( SELECT, LOW);
  delayMicroseconds(20);
  digitalWrite( buttonOutStart, digitalRead( buttonTwo ));
  digitalWrite(SELECT, HIGH);
}

void loop()
{
  readPins();
  delay(5); // Delays 10 milliseconds, which should be sub-frame.  adjust as needed
}
