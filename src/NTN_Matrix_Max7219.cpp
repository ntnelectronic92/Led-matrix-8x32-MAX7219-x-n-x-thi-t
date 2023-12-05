#include "NTN_Matrix_Max7219.h"
#include "NTN_Include_All.h"
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
const char *arrstring[]
{
  "Welcome to NTN.ELECTRONIC Youtube channel",
  "Xin chào các bạn đến kênh NTN.ELECTRONIC"
};

ST_SPRITE sprite[] =
{
  { walker, W_WALKER, F_WALKER },
  { invader, W_INVADER, F_INVADER },
  { chevron, W_CHEVRON, F_CHEVRON },
  { heart, W_HEART, F_HEART },
  { arrow1, W_ARROW1, F_ARROW1 },
  { steamboat, W_STEAMBOAT, F_STEAMBOAT },
  { fireball, W_FBALL, F_FBALL },
  { rocket, W_ROCKET, F_ROCKET },
  { roll2, W_ROLL2, F_ROLL2 },
  { pacman2, W_PMAN2, F_PMAN2 },
  { lines, W_LINES, F_LINES },
  { roll1, W_ROLL1, F_ROLL1 },
  { sailboat, W_SAILBOAT, F_SAILBOAT },
  { arrow2, W_ARROW2, F_ARROW2 },
  { wave, W_WAVE, F_WAVE },
  { pacman1, W_PMAN1, F_PMAN1 }
};
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
textEffect_t _textEffect_In  = PA_NO_EFFECT;
textEffect_t _textEffect_Out = PA_NO_EFFECT;

void NTN_Maxtrix_Max7219_Initial() {
  myDisplay.begin();
  myDisplay.setIntensity(8);
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.setSpeed(60);
  myDisplay.setPause(300);
  myDisplay.displayClear();
}

void NTN_Maxtrix_Max7219_Handler() 
{
  if (myDisplay.displayAnimate())
  {
    Serial.printf("NUMBER SPRITE = %d \r\n", NUMBER_SPRITE);
    switch (USER_DATA.effectNumber)
    {
      case EFFECT_SCROLL:
        _textEffect_In  = PA_SCROLL_LEFT;
        _textEffect_Out = PA_SCROLL_LEFT;
        myDisplay.displayText(arrstring[0], myDisplay.getTextAlignment(), myDisplay.getSpeed(), myDisplay.getPause(), _textEffect_In,_textEffect_Out);
        break;
      case EFFECT_SCROLL_LEFT_SPRITE:
       _textEffect_In = PA_SCROLL_LEFT;
       _textEffect_Out = PA_SPRITE;
       myDisplay.setSpriteData( sprite[USER_DATA.indexSprite].data, sprite[USER_DATA.indexSprite].width, sprite[USER_DATA.indexSprite].frames,sprite[(USER_DATA.indexSprite +1)%NUMBER_SPRITE].data, sprite[(USER_DATA.indexSprite +1)%NUMBER_SPRITE].width, sprite[(USER_DATA.indexSprite +1)%NUMBER_SPRITE].frames);
       myDisplay.displayText(arrstring[0], myDisplay.getTextAlignment(), myDisplay.getSpeed(), myDisplay.getPause(), _textEffect_In,_textEffect_Out);
       break;
      case EFFECT_HELL0_SPRITE:
       _textEffect_In = PA_SPRITE;
       _textEffect_Out = PA_SPRITE;
       myDisplay.setSpriteData( sprite[USER_DATA.indexSprite].data, sprite[USER_DATA.indexSprite].width, sprite[USER_DATA.indexSprite].frames,sprite[(USER_DATA.indexSprite +1)%NUMBER_SPRITE].data, sprite[(USER_DATA.indexSprite +1)%NUMBER_SPRITE].width, sprite[(USER_DATA.indexSprite +1)%NUMBER_SPRITE].frames);
       myDisplay.displayText("Hello", myDisplay.getTextAlignment(), myDisplay.getSpeed(), myDisplay.getPause(), _textEffect_In,_textEffect_Out);
       break;
      default:
      break;
    }
    myDisplay.displayReset();
  }
}
