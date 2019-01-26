

#define encoder0PinA  2 //eda encoder a pin digital pin 2 
#define encoder0PinB  4 // encoder pin b to digital pin 4

unsigned int encoder0Pos=0;
int newposition;
int oldposition;
int newtime;
int oldtime;
float vel;
void setup()
{

  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       
  attachInterrupt(0, doEncoder, RISING);  
  Serial.begin (9600);
  Serial.println("start");                

}

void loop()
{
newposition = encoder0Pos;
newtime = (0.001*millis());
vel = (newposition-oldposition)/(newtime-oldtime);
Serial.print ("\n speed = ");
Serial.print (vel);// variable to measure the velocity of the bike  
oldposition = newposition;
oldtime = newtime;
delay(1000);
}

void doEncoder()
{
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }

 // Serial.println (encoder0Pos, DEC);
}
