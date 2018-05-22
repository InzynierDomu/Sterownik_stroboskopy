#define POT1_PIN A0
#define POT2_PIN A1
#define POT3_PIN A2
#define POT4_PIN A3
#define OSC1_PIN 5
#define OSC2_PIN 6

int MeasurePot1 = 0;  //T11
int MeasurePot2 = 0;  //T12
int MeasurePot3 = 0;  //T21
int MeasurePot4 = 0;  //T22

int CounterT11 = 0;  
int CounterT12 = 0;
int CounterT21 = 0;
int CounterT22 = 0;

bool Oscillator1High = false;
bool Oscillator2High = false;

void setup() {
  pinMode(OSC1_PIN, OUTPUT);
  pinMode(OSC2_PIN, OUTPUT);
  digitalWrite(OSC1_PIN, LOW);  
  digitalWrite(OSC2_PIN, LOW);  
}

void loop() {
  Measurement();

  if (Oscillator1High)
  {
    CounterT11++;
  }else{
    CounterT12++;    
  }

  if (CounterT11 >= MeasurePot1)
  {
    digitalWrite(OSC1_PIN, LOW);
    Oscillator1High = !Oscillator1High;
    CounterT11 = 0;
  }
  else if(CounterT12 >= MeasurePot2)
  {
    digitalWrite(OSC1_PIN, HIGH); 
    Oscillator1High = !Oscillator1High;
    CounterT12 = 0;
  }
  else
  {
    
  }

  if (Oscillator2High)
  {
    CounterT21++;
  }else{
    CounterT22++;    
  }

  if (CounterT21 >= MeasurePot3)
  {
    digitalWrite(OSC2_PIN, LOW);
    Oscillator2High = !Oscillator2High;
    CounterT21 = 0;
  }
  else if(CounterT22 >= MeasurePot4)
  {
    digitalWrite(OSC2_PIN, HIGH);   
    Oscillator2High = !Oscillator2High;
    CounterT22 = 0;
  }
  else
  {
    
  }

  delay(4);  
}

void Measurement()
{
  MeasurePot1 = (analogRead(POT1_PIN) / 2) + 2;
  MeasurePot2 = analogRead(POT2_PIN) / 2;
  MeasurePot3 = (analogRead(POT3_PIN) / 2) + 2;
  MeasurePot4 = analogRead(POT4_PIN) / 2;
}
