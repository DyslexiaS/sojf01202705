const unsigned long MIN_PRESSURE = 0UL;
const unsigned long MAX_PRESSURE = 1200000UL;  // 1.2 MPa
const int MIN_READING = 1024 * 0.5 / 5;
const int MAX_READING = 1024 * 4.5 / 5; 
int in;
unsigned long pressure_in_Pascals;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  in=analogRead(A0);
  if(in<102)
  {
     pressure_in_Pascals=0;
  }
  else
  {
      pressure_in_Pascals = map(in, MIN_READING, MAX_READING, MIN_PRESSURE, MAX_PRESSURE);//map(value, fromLow, fromHigh, toLow, toHigh);
  }
  //Re-maps a number from one range to another. That is, a value of fromLow would get mapped to toLow, a value of fromHigh to toHigh, values in-between to values in-between, etc. 
  Serial.println(pressure_in_Pascals);
  Serial.println(in);
}
