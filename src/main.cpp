#include <Arduino.h>
#include <PikBtLib.h>
#include <PikMotorL298NLib.h>
#include <PikUltraSonicLib.h>


PikMotorL298N motor(14,27,26,25,13,12);
PikUltraSonic sonic(2,4);
PikBt Bt = PikBt();
void setup() {
  Serial.begin(9600);
  Bt.Init("kelian");
}

void loop() {
  if(Bt.Available()){
    char s = Bt.ReadChar();
    if(s=='z'){motor.Forward(5);
    Bt.SendMsg("forw");}
    if(s=='s'){motor.BackWark(5);
    Bt.SendMsg("back");}
    if(s=='q'){motor.TurnLeft(5);
    Bt.SendMsg("left");}
    if(s=='d'){motor.TurnRight(5);
    Bt.SendMsg("right");}
    if(s=='e'){motor.Stop();
    Bt.SendMsg("stop");}
    Bt.SendMsg("ok");
  }
  delay(10);
  float x = sonic.GetDistanceCm();
  Serial.println(x);
  if(x < 5){
   motor.Stop(); 
  }
}