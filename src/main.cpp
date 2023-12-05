#include "NTN_Include_All.h"

void setup()
{
  NTN_App_Initial();
  NTN_Time_Init();
}

void loop()
{
  NTN_Time_Handler();
  NTN_App_Handler();
}
