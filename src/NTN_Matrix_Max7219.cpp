#include "NTN_Matrix_Max7219.h"
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
const char *arrstring[]
{
  "NTN",
  "Hello",
  "Elec",
  "Welcome",
};
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

uint i = 0;

textEffect_t texteffect[] = {
  PA_WIPE,
  PA_WIPE_CURSOR,
  PA_OPENING_CURSOR,
  PA_CLOSING_CURSOR,
  PA_BLINDS,
  PA_MESH,
  PA_OPENING,
  PA_CLOSING,
  PA_SCAN_VERT,
  PA_DISSOLVE,
  PA_RANDOM,
  PA_PRINT,
  PA_SCROLL_RIGHT,
  PA_SCROLL_LEFT,
  PA_GROW_UP,
  PA_GROW_DOWN,
  PA_SCROLL_UP,
  PA_SCROLL_DOWN,
  PA_SCROLL_UP_RIGHT,
  PA_SCROLL_UP_LEFT,
  PA_SCROLL_DOWN_RIGHT,
  PA_SCROLL_DOWN_LEFT,
};
void NTN_Maxtrix_Max7219_Initial() {
  myDisplay.begin();
  myDisplay.setIntensity(13);
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.setSpeed(60);
  myDisplay.setPause(1000);
  myDisplay.displayClear();
}

void NTN_Maxtrix_Max7219_Handler() 
{
  int static stringIndex = 0;
  if (myDisplay.displayAnimate()) {
    if (i < sizeof(texteffect)) {
      i++;
    }
    else {
      i = 0;
    }
    myDisplay.displayText(arrstring[(stringIndex++%4)], myDisplay.getTextAlignment(), myDisplay.getSpeed(), myDisplay.getPause(), texteffect[i], texteffect[i]);
    myDisplay.displayReset();
  }
}
