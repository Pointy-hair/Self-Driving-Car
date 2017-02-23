//J.R.
# include <Arduino.h>
# include <Servo.h>

Servo gas;
Servo brake;
Servo wheel;

int wheelAngle=0;
int gasAngle=0;
boolean brakingAngle=false;

void setup(){
  Serial.begin(9600);
  while(!Serial){}
  gas.attach(9);
  brake.attach(10);
  wheel.attach(11);
}



void loop(){
  if(Serial.available()>0){
    if(Serial.read()==true && brakeAngle == false){
      brakeAngle==true;
      brake.write(x); //x is value to be added
    }
    if(Serial.read()==false && brakeAngle == true){
      brakeAngle==false;
      brake.write(x); //x is value to be added
    }
    if(Serial.read()[0]=="g"){
      //gasAngle=(int)(Serial.read()[1,strlen()-1]);
      gasAngle = (int) Serial.parseInt();
      gas.write(gasAngle);
    }
    if(Serial.read()[0]=="w"){
      //wheelAngle=(int)(Serial.read()[1,strlen()-1]);
      wheelAngle = (int) Serial.parseInt();
      wheel.write(wheelAngle);
    }
  }
}