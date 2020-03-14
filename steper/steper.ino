#include <Servo.h>
Servo servoRigthBedro, servoRightGolen, servoRightStopa; 
Servo servoLeftBedro, servoLeftGolen, servoLeftStopa; 

//базовое положение
const double positionStensd [6] = {55, 90, 120, 115, 105, 20};

double nullPosition [6] = {0, 0, 0, 0, 0, 0};

//разбиение шага
const int defferenc = 40;


void setPosition (double pos [6]);
void moveToPositionVector (double pos [6]); 
void stepLeft ();
void dance1(int pa);
void dance2(int pa);
void hello ();

void setup()
{
   servoRigthBedro.attach (3);
   servoRightGolen.attach (5);
   servoRightStopa.attach (6);
   servoLeftBedro.attach  (9);
   servoLeftGolen.attach  (10);
   servoLeftStopa.attach  (11);
   setPosition (positionStensd);
   
   Serial.begin(9600);
   
}

//================================================================================
void loop(){

   dance1(1);
   dance2(3);
   hello();
   delay (1000);
   for (int i = 1; i<10; i++) {
      stepLeft();
   }  
}
//================================================================================
void setPosition (double pos [6]){
   servoRigthBedro.write(pos[0]);
   servoRightGolen.write(pos[1]);
   servoRightStopa.write(pos[2]);
   servoLeftBedro.write(pos[3]);
   servoLeftGolen.write(pos[4]);
   servoLeftStopa.write(pos[5]);
}

void moveToPositionVector (double pos [6]){
  double targetEngle [6] = {   positionStensd[0]+pos[0], 
                              positionStensd[1]+pos[1], 
                              positionStensd[2]-pos[2], 
                              positionStensd[3]-pos[3], 
                              positionStensd[4]-pos[4], 
                              positionStensd[5]+pos[5]};
  double startEngle [6] = {   servoRigthBedro.read(),
                              servoRightGolen.read(),
                              servoRightStopa.read(),
                              servoLeftBedro.read(),
                              servoLeftGolen.read(),
                              servoLeftStopa.read()};
  
  double microStep [6] = {0};
  for (int i = 0; i<6; i++) {
      microStep [i] = (targetEngle[i] - startEngle[i]) / defferenc;
  }
  
  for (int i = 0; i<defferenc; i++) {
      for (int serva = 0; serva<6; serva++) {
          startEngle[serva] =  startEngle[serva] + microStep [serva];
          //Serial.print (startEngle[serva]);
          //Serial.print (" ");
      }
    
      setPosition (startEngle);
      delay(10);  // SPEED----------------------------------------------
  }
  
  setPosition (targetEngle);
}

//------------------------------------------------------------------------
void stepLeft () {
    double position [6] = {0, 0, 20, 30, 30, -20};
    moveToPositionVector (position);
    position [0] = 80;
    position [1] = 30;
    moveToPositionVector (position);
    //delay(1000);
    position [3] = 0;
    position [4] = 0;
    moveToPositionVector (position);
    //delay(1000);
    position [3] = -20;
    position [4] = -20;
    moveToPositionVector (position);
    //delay(1000);
    position [0] = 30;
    position [1] = 30;
    position [2] = 0;
    position [3] = -20;
    position [4] = -20;
    position [5] = 0;
    moveToPositionVector (position);
    //delay(1000);
    position [2] = -20;
    position [5] = 20;
    moveToPositionVector (position);
    //delay(1000);
    
    
    //------------
    moveToPositionVector (position);
    position [3] = 80;
    position [4] = 30;
    moveToPositionVector (position);
    //delay(1000);
    position [0] = 0;
    position [1] = 0;
    moveToPositionVector (position);
    //delay(1000);
    position [0] = -20;
    position [1] = -20;
    moveToPositionVector (position);
    //delay(1000);
    position [3] = 30;
    position [4] = 30;
    position [5] = 0;
    position [0] = -20;
    position [1] = -20;
    position [2] = 0;
    moveToPositionVector (position);
    //delay(1000);
    position [5] = -20;
    position [2] = 20;
    moveToPositionVector (position);
    //delay(1000);  
}
//------------------------------------------------------------------------

void dance1(int pa){
   double position1 [6] = {30, 30, 0, -30, -30, 0};
   double position2 [6] = {-30, -30, 0, 30, 30, 0};
   for (int i = 0; i<pa; i++) {
      moveToPositionVector (position1);
      delay (100);
      
   moveToPositionVector (nullPosition);
   delay (100);
      moveToPositionVector (position2);
      
      delay (100);
   }
   moveToPositionVector (nullPosition);
}

void dance2 (int pa){
   double position [6] = {30, 30, 30, 30, 30, 30};
   for (int i = 1; i<pa; i++) {
      moveToPositionVector (position);
      delay (100);

      moveToPositionVector (nullPosition);
      delay (100);
   }
}

void hello () {
    double position [6] = {0, 0, 20, 30, 30, -20};
    moveToPositionVector (position);
    position [0] = 90;
    position [1] = 30;
    moveToPositionVector (position);
    delay(1000);
    position [1] = 0;
    moveToPositionVector (position);
    delay(1000);
    position [1] = -30;
    moveToPositionVector (position);
    for (int i = 0; i<4; i++) {
      position [2] = 30;
      moveToPositionVector (position);
      position [2] = -30;
      moveToPositionVector (position);
    }
    position [2] = 20;
    moveToPositionVector (position);
    position [0] = 90;
    position [1] = 30;
    moveToPositionVector (position);
    double position1 [6] = {0, 0, 20, 30, 30, -20};
    moveToPositionVector (position1);
    moveToPositionVector (nullPosition);
      
}
