#define potPin1 A0
#define potPin2 A1
#define potPin3 A2
#define potPin4 A3

int measurePot1 = 0;  //T11
int measurePot2 = 0;  //T12
int measurePot3 = 0;  //T21
int measurePot4 = 0;  //T22

int counterT11 = 0;
int counterT12 = 0;
int counterT21 = 0;
int counterT22 = 0;

bool osc1 = false;
bool osc2 = false;

void setup() {
 
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(5, LOW);  
  digitalWrite(6, LOW);  
  digitalWrite(7, LOW);  
  digitalWrite(8, LOW); 
}

void loop() {

  Measurement();

  if (osc1)
  {
    counterT11 ++;
  }else{
    counterT12 ++;    
  }

  if (counterT11 >= measurePot1)
  {
    digitalWrite(5, LOW);
    digitalWrite(7, HIGH);
    osc1 = !osc1;
    counterT11 = 0;
  }
  else if(counterT12 >= measurePot2)
  {
    digitalWrite(5, HIGH); 
    digitalWrite(7, LOW);  
    osc1 = !osc1;
    counterT12 = 0;
  }else
  {
    
  }

  if (osc2)
  {
    counterT21 ++;
  }else{
    counterT22 ++;    
  }

  if (counterT21 >= measurePot3)
  {
    digitalWrite(6, LOW);
    digitalWrite(8, HIGH);
    osc2 = !osc2;
    counterT21 = 0;
  }
  else if(counterT22 >= measurePot4)
  {
    digitalWrite(6, HIGH);   
    digitalWrite(8, LOW);
    osc2 = !osc2;
    counterT22 = 0;
  }else
  {
    
  }

  delay(4);  
}

void Measurement()
{
  measurePot1 = (analogRead(potPin1) / 2) + 2;
  measurePot2 = analogRead(potPin2) / 2;
  measurePot3 = (analogRead(potPin3) / 2) + 2;
  measurePot4 = analogRead(potPin4) / 2;
}
