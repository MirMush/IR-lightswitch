#include <IRremote.h>
#include  <Servo.h>
int ledPin=8;
int IRpin=9;
IRrecv IR(IRpin);
decode_results cmd;
int servopos1=180;
int servopos2=0;
int servopin=3;
int finalpos= 90;
Servo myservo;


void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
 myservo.attach(servopin);
 pinMode(ledPin,OUTPUT);
}

void loop() {
  digitalWrite(ledPin,HIGH);
  
  
  while(IR.decode(&cmd)==0) {

}

Serial.println(cmd.value,HEX);
delay(500);
IR.resume();
if (cmd.value==0xFD20DF)  {

 
myservo.write(servopos1);


}


 else if (cmd.value== 0xFD609F ) {
  

  
myservo.write(servopos2);


  }

  else {

 
    myservo.write(finalpos);

  }


  

}
