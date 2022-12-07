#include <Arduino.h>
#include <LiquidCrystal.h>


//--------------------------------------------

//RELAY PINS************
#define air_pump = 12;
#define motor_conv = 11;
#define pump_filling = 10;
#define motor_cap = 9;

//------------------------------------------

//IR SENSOR PINS**************
#define ir_start = 8;
#define ir_fill = 6;
#define ir_CAP = 7;
//-----------------------------------------

//BUZZER PIN**********************
#define buz = A2;
//------------------------------------------


//STEPPER MOTOR PINS********************
#define en_stepper 3
const int StepX = A3;
const int DirX = A4;
int pulseWidthMicros = 1000;  // microseconds
int millisBtwnSteps = 15000;


// Initialise the LCD with the arduino. LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(A5, A6, 4, 5, 6, 7);

void setup() {

}

void loop() {
 
}
