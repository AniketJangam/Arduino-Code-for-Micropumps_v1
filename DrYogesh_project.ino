const int micropump_1 =  13;      // The pin number of the Micropump1 
const int micropump_2 = 12;       // The pin number of the Micropump2
int clk = 9;                      // The pin number for the clock input


void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 9 || pin == 10) {
    switch(divisor) {
      case 1562: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } 
}

void setup() 
{
  setPwmFrequency(9,1562);  //Setting the frequency to 20Hz
  pinMode(clk, OUTPUT);
  pinMode(micropump_1, OUTPUT);
  pinMode(micropump_2, OUTPUT);
}

void loop() 
{
  delay(3000);
  analogWrite(9,90);                 // setting the duty cycle to 50%
  digitalWrite(micropump_1, HIGH);   // turn the micropump 1 on
  delay(3000);                       // wait for 3 seconds
  digitalWrite(micropump_2, HIGH);   // turn the micropump 2 on
}

//Written by Aniket Jangsm on March 10,2017
