#include "NTN_Time.h"


void Timer1us();
void Timer1ms();
void Timer100ms();
void Timer1s();
void Timer5s();
void Timer30s();

bool ledState;
int counterUS;

Ticker timer1(Timer1us, 1, 0, MICROS);
Ticker timer2(Timer1ms, 1000, 0, MICROS);
Ticker timer3(Timer100ms, 100, 0, MILLIS);
Ticker timer4(Timer1s, 1000,0, MILLIS);
Ticker timer5(Timer5s, 5000, 0, MILLIS);
Ticker timer6(Timer30s, 30000, 0, MILLIS);

void NTN_Time_Init(void)
{
  timer1.start();
  timer2.start();
  timer3.start();
  timer4.start();
  timer5.start();
  timer6.start();
}

void NTN_Time_Handler(void)
{
  timer1.update();
  timer2.update();
  timer3.update();
  timer4.update();
  timer5.update();
  timer6.update();
}

void Timer1us()
{

}
void Timer1ms()
{

}
void Timer100ms()
{

}
void Timer1s()
{

}
void Timer5s()
{

}
void Timer30s()
{
    USER_DATA.effectNumber++;
    USER_DATA.indexSprite++;
    if(USER_DATA.effectNumber>= EFFECT_MAX)
    {
        USER_DATA.effectNumber = 0;
    }
    if(USER_DATA.indexSprite>= 15)
    {
      USER_DATA.indexSprite = 0;
    }
    Serial.printf("Start timer 30S \r\n");
}
