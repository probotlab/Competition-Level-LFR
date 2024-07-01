#include <AFMotor.h>

AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

#define RM_S A0
#define R_S A1
#define M_S A2
#define L_S A3
#define LM_S A4

int lms,ls,ms,rs,rms ;
int check=0;

void setup() {

  Serial.begin(9600);
  
  pinMode(R_S, INPUT);
  pinMode(M_S, INPUT);
  pinMode(L_S, INPUT);
  pinMode(RM_S, INPUT);
  pinMode(LM_S, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);
 
}

void loop() {

Serial.print(lms);
Serial.print(ls);
Serial.print(ms);
Serial.print(rs);
Serial.println(rms);

readsensors();
followline();

}

void followline()
{

if (lms==1 && ls==0  && ms==0 && rs==0 && rms==1)                                     
{
 forward();
}
else if (lms==0 && ls==0  && ms==0 && rs==0 && rms==0)                                     
{
 forward();
}
else if (lms==1 && ls==1  && ms==0 && rs==1 && rms==1)                                     
{
 // check=0;
forward();
}
else if (lms==1 && ls==1  && ms==0 && rs==0 && rms==1)                                     
{//check=0;
turnRight();
}
else if (lms==1 && ls==1  && ms==1 && rs==0 && rms==1)                                     
{//check=0;
turnRight();
}

else if (lms==1 && ls==1  && ms==1 && rs==0 && rms==0)                                    
{//check=2;
turnRight();
}
else if (lms==1 && ls==1  && ms==1 && rs==1 && rms==0)                                      
{//check=2;
midturnRight();
}
else if (lms==1 && ls==0  && ms==0 && rs==0 && rms==0)                                     
{//check=2;
turnRight();
}

else if (lms==1 && ls==0  && ms==0 && rs==1 && rms==1)                                      
{//check=0;
turnLeft();
}
else if (lms==1 && ls==0  && ms==1 && rs==1 && rms==1)                                      
{
  //check=0;
turnLeft();
}
else if (lms==0 && ls==0  && ms==1 && rs==1 && rms==1)                                      
{//check=1;
turnLeft();
}
else if (lms==0 && ls==1  && ms==1 && rs==1 && rms==1)                                      
{//check=1;
midturnLeft();
}

  else if (lms == 1 && ls == 1  && ms == 1 && rs == 1 && rms == 1)                            
  {
    if(check==1)
   {
   // readsensors();
        sharpturnLeft();
    
  }
  if(check==2)
  {
    //readsensors(); 
        sharpturnRight();
    
  }
  

  }
}

void readsensors(){
  lms = digitalRead(LM_S);
  ls = digitalRead(L_S);
  ms = digitalRead(M_S);
  rs = digitalRead(R_S);
  rms = digitalRead(RM_S);


if(lms==0)
{
  check=1;
}
else if(rms==0)
{
  check=2;
}
  
    
}

void forward(){

  motor3.setSpeed(125);
  motor4.setSpeed(125);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
    
} 

void turnRight(){

  motor3.setSpeed(130);
  motor4.setSpeed(0);
  motor3.run(BACKWARD);
  motor4.run(RELEASE);

  }


void sharpturnRight(){
  
  motor3.setSpeed(140);
  motor4.setSpeed(140);

   motor3.run(BACKWARD);
   motor4.run(FORWARD);
   
  }
  void midturnRight(){

  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  

  }

void turnLeft(){

  motor3.setSpeed(0);
  motor4.setSpeed(130);
  motor4.run(BACKWARD);
  motor3.run(RELEASE);

}
void sharpturnLeft(){
  
  motor3.setSpeed(140);
  motor4.setSpeed(140);

  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  
}

void midturnLeft(){

  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);

}

void stop(){

  motor3.setSpeed(0);
  motor4.setSpeed(0);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
 
}
