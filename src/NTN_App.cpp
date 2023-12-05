#include "NTN_App.h"
void NTN_App_Initial(void)
{
    Serial.begin(115200);
    NTN_Maxtrix_Max7219_Initial();
}

void NTN_App_Handler(void)
{
   NTN_Maxtrix_Max7219_Handler();
}