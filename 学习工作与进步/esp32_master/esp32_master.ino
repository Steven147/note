//蓝牙定义
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;

//命令变量定义
int cmd = 48;
int commands[] = {32,29,28,31,30,53,54,55,56};

//引脚名定义
int in1 = 2, in2 = 0, in3 = 4, in4 = 16, in5 = 27 , in6 = 32, in7 = 33, in8 =25, 
enable_slide34 = 14, enable_alarm = 23,
enable_servo1 = 22, enable_servo2 =23;

int alarm_state = HIGH;

void setup()
{
  Serial.begin(115200);
  SerialBT.begin("f2_ESP32test"); //Bluetooth device name
  //Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  pinMode(enable_slide34, OUTPUT);
  
  pinMode(enable_servo1, OUTPUT);
  pinMode(enable_servo2, OUTPUT);

  pinMode(enable_alarm, OUTPUT);
  digitalWrite(enable_servo1, alarm_state);
}

void loop() 
{
  if (SerialBT.available()) 
  {
     cmd = SerialBT.read();
     SerialBT.write(cmd); //将接收到的信号以ascii码发回去  
     Serial.println(cmd);
  }

  // in1H + in2L = motor1 顺时针
  // in4H + in3L = motor2 顺时针

  if(cmd == commands[0])//0 stop
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8, LOW);
    digitalWrite(enable_slide34, LOW);

    digitalWrite(enable_servo1, LOW);
    digitalWrite(enable_servo2, LOW);
  }
  else if(cmd == commands[1])// 1 move forward ：motor1逆时针、motor2顺时针
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH); 
  }
  else if(cmd == commands[2])//2 move backward ：motor1顺时针、motor2逆时针
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if(cmd == commands[3])//3 move left ：motor1顺时针、motor2顺时针
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else if(cmd == commands[4])//4 move left ：motor1逆时针、motor2顺时针
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if(cmd == commands[5])//5 move forward slideway
  {
    
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    digitalWrite(in7, HIGH);
    digitalWrite(in8, LOW);
    digitalWrite(enable_slide34, HIGH);
    
  }
  else if(cmd == commands[6])//6 move forward slideway
  {
    
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    digitalWrite(in7, LOW);
    digitalWrite(in8, HIGH);
    digitalWrite(enable_slide34, HIGH);
    
  }
  else if(cmd == commands[7])//7 move up arm
  {
    
    digitalWrite(enable_servo1, HIGH);
    digitalWrite(enable_servo2, LOW);
    
  }
  else if(cmd == commands[8])//8 move down arm
  {
    digitalWrite(enable_servo1, LOW);
    digitalWrite(enable_servo2, HIGH);
  }
  /*
  else if(cmd == commands[9])//9 switch alarm
  {
    alarm_state = !alarm_state;
    Serial.println(alarm_state);
    digitalWrite(enable_servo1, alarm_state);
  }
  */
}
