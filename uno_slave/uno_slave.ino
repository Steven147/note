#include <Servo.h> 
Servo servo1, servo2;

int pos = 0;
bool up, down;

int enable_alarm = 3, enable_slide1 = 0, enable_slide2 = 1, enable_servo1 = 4, enable_servo2 = 5, alarm = 8, 
slide1 = 6, slide2 = 7, s1 = 11, s2 = 12, TrigPin = 2, EchoPin = 3; 
float cm; 

void setup() 
{
  pinMode(enable_alarm, INPUT);
  pinMode(enable_slide1, INPUT);
  pinMode(enable_slide2, INPUT);
  pinMode(enable_servo1, INPUT);
  pinMode(enable_servo2, INPUT);
  
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  pinMode(slide1,OUTPUT);
  pinMode(slide2,OUTPUT);
  servo1.attach(s1);
  servo2.attach(s2);
  servo1.write(180 - pos);
  servo2.write(pos);

  Serial.begin(9600);
  pinMode(alarm, OUTPUT);
  up = false;
  down = false;
}

void loop() 
{
  //servo
  if(analogRead(enable_servo1) > 200 and analogRead(enable_servo2) < 200) 
  {
    up = true;
    down = false;
  }
  else if(analogRead(enable_servo1) < 200 and analogRead(enable_servo2) > 200) 
  {
    up = false;
    down = true; 
  }
  //servo stop
  else 
  {
    up = false;
    down = false;
  }
  
  //servo move
  if(up) {
    pos++;
    if(pos <= 180) {
      servo1.write(180 - pos); 
      servo2.write(pos);
    }
    else pos--;
    delay(50);  
  }
  
  if(down){
    pos--;
    if(pos >= 0) {
      servo1.write(180 - pos); 
      servo2.write(pos);
    }
    else pos++;
    delay(50);
  }

  
  //echo - alarm
  
  digitalWrite(TrigPin, LOW); //低高低电平发一个短时间脉冲去TrigPin 
  delayMicroseconds(2); 
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TrigPin, LOW); 
  cm = pulseIn(EchoPin, HIGH) / 58.0; //将回波时间换算成cm 
  cm = (int(cm * 100.0)) / 100.0; //保留两位小数 
  Serial.print(cm); 
  Serial.print("cm"); 
  Serial.println(analogRead(enable_alarm)); 
  if(cm < 40 and cm > 0){ //and analogRead(enable_alarm) > 200
    tone(alarm, 500);
  }
  else noTone(alarm);

  
  if(analogRead(enable_slide1) > 200 and analogRead(enable_slide2) < 200) 
  {
    digitalWrite(slide1, HIGH);
    digitalWrite(slide2, LOW);
  }
  else if(analogRead(enable_slide1) < 200 and analogRead(enable_slide2) > 200) 
  {
    digitalWrite(slide1, LOW);
    digitalWrite(slide2, HIGH); 
  }
  else
  {
    digitalWrite(slide1, LOW);
    digitalWrite(slide2, LOW); 
  }

}
