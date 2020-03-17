#include <IOShieldOled.h>

void setup()
{
  IOShieldOled.begin();
}

void loop()
{
  int irow;
  int ib;

  //Clear the virtual buffer
 // IOShieldOled.clearBuffer();

  //Chosing Fill pattern 0
 // IOShieldOled.setFillPattern(IOShieldOled.getStdPattern(0));
  //Turn automatic updating off
 // IOShieldOled.setCharUpdate(0);
/*
  //Draw a rectangle over wrting then slide the rectagle
  //down slowly displaying all writing
  for (irow = 0; irow < IOShieldOled.rowMax; irow++)
  {
    IOShieldOled.clearBuffer();
    IOShieldOled.setCursor(0, 0);
    IOShieldOled.putString("chipKIT");
    IOShieldOled.setCursor(0, 1);
    IOShieldOled.putString("Basic I/O Shield");
    IOShieldOled.setCursor(0, 2);
    IOShieldOled.putString("by Digilent");

    IOShieldOled.moveTo(0, irow);
    IOShieldOled.drawFillRect(127, 31);
    IOShieldOled.moveTo(0, irow);
    IOShieldOled.drawLine(127, irow);
    IOShieldOled.updateDisplay();
    delay(50);
  }

  delay(1000);

  // Blink the display a bit.
  IOShieldOled.displayOff();
  delay(100);
  IOShieldOled.displayOn();
  delay(100);

  IOShieldOled.displayOff();
  delay(100);
  IOShieldOled.displayOn();
  delay(100);

  IOShieldOled.displayOff();
  delay(100);
  IOShieldOled.displayOn();
  delay(100);

  delay(1000);
*/


  // Draw a rectangle in center of screen
  // Display the 8 different patterns availible
  IOShieldOled.setDrawMode(IOShieldOled.modeSet);

    while (1) {
    int potenciometr = map(analogRead (A0), 0 ,1023, 0, 128);
    //for (ib = 1; ib < 8; ib++)
    //{
      IOShieldOled.clearBuffer();

      IOShieldOled.setFillPattern(IOShieldOled.getStdPattern(1));
      IOShieldOled.moveTo(1, 1);
      IOShieldOled.drawFillRect(potenciometr, 27);
      IOShieldOled.drawRect(potenciometr, 27);
      IOShieldOled.updateDisplay();

      delay(10);
    //}
  }
}
