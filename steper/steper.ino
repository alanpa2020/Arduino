#include <Servo.h>
Servo servoRigthBedro, servoRightGolen, servoRightStopa; 
Servo servoLeftBedro, servoLeftGolen, servoLeftStopa; 

const int positionStensd [6] = {70, 90, 120, 100, 105, 20};

void setPosition (int pos [6]);
void moveToPosition (int pos [6]); 

void setup()
{
   servoRigthBedro.attach(3);
   servoRightGolen.attach(5);
   servoRightStopa.attach(6);
   servoLeftBedro.attach(9);
   servoLeftGolen.attach(10);
   servoLeftStopa.attach(11);
   setPosition (positionStensd);
}
 
void loop()
{
   setPosition (positionStensd);
   delay (500);
   int position [6] = {30, 0, 0, 30, 0, 0};
   moveToPosition (position);
   delay (500);
   for (int i = 0; i < 6; i++) {
      position [i] = 0;
   }
   moveToPosition (position);
   
}

void setPosition (int pos [6]){
   servoRigthBedro.write(pos[0]);
   servoRightGolen.write(pos[1]);
   servoRightStopa.write(pos[2]);
   servoLeftBedro.write(pos[3]);
   servoLeftGolen.write(pos[4]);
   servoLeftStopa.write(pos[5]);
}

void moveToPosition (int pos [6]){
  int naturalEngle [6] = {positionStensd[0]-pos[0], 
                          positionStensd[1]-pos[1], 
                          positionStensd[2]-pos[2], 
                          positionStensd[3]+pos[3], 
                          positionStensd[4]+pos[4], 
                          positionStensd[5]+pos[5]};
  setPosition (naturalEngle);
}
