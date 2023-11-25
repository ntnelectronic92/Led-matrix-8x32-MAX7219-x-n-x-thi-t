#ifndef _NTN_MATRIX_MAX7219_H_
#define _NTN_MATRIX_MAX7219_H_
#include <Arduino.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN   D5
#define DATA_PIN  D7
#define CS_PIN    D8
#define PAUSE_TIME    1000
#define SCROLL_SPEED  50
void NTN_Maxtrix_Max7219_Initial(void);
void NTN_Maxtrix_Max7219_Handler(void);
#endif