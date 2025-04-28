#define trig_pin 2
#define Echo_pin 3
#define green_light 6
#define red_light 5
#define blue_light 4
void setup()
{
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(Echo_pin, INPUT);
  pinMode(blue_light, OUTPUT); 
  pinMode(red_light, OUTPUT);
  pinMode(green_light, OUTPUT);
}
void loop()
{
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);//extra
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);

  long duration = pulseIn(Echo_pin,HIGH);
  float distance= duration*0.034/2; //unit of v(air)=cm/microsecond
  Serial.print(distance);//serial print line
  Serial.println(" cm");
  delay(100);

   if(distance<15)
  {
    digitalWrite(green_light,HIGH);
  }
  else
  digitalWrite(green_light,LOW);

   if(distance<10)
  {
    digitalWrite(red_light, HIGH);
  }
  else
  digitalWrite(red_light,LOW);

  if(distance<5)
  {
    digitalWrite(blue_light,HIGH);
  }
  else
  digitalWrite(blue_light,LOW);

}
