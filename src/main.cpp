#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>


// Initialise the LCD with the arduino. LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(A6, A7, 2, 3, 4, 5);

//--------------------------------------------

//RELAY PINS************
#define air_pump  12
#define motor_conv  11
#define pump_filling  10
#define motor_cap  9

//------------------------------------------

//IR SENSOR PINS**************
#define ir_start  8
#define ir_fill  6
#define ir_CAP  7
//-----------------------------------------

//BUZZER PIN**********************
#define buz  A2
//------------------------------------------


//STEPPER MOTOR PINS********************
#define en_stepper 13
#define StepX A3
#define DirX  A4
int pulseWidthMicros = 1000;  // microseconds
int millisBtwnSteps = 15000;

void CheckCap();
void CheckBottol();
void InitialPositionSet();
void CircleRotorStepper(int x);
void FillPump(int status);
void CapSetPump(int status);

void setup() {

}

void loop() {
 
}



void CircleRotorStepper(int x)
{
  if (x == 1)
  {
    digitalWrite(en_stepper, LOW);
    // digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
    // Makes 200 pulses for making one full cycle rotation
    digitalWrite(StepX, HIGH);
    delayMicroseconds(1000);
    digitalWrite(StepX, LOW);
    delayMicroseconds(1000);
  }
  if (x == 0)
    digitalWrite(en_stepper, HIGH); // digitalWrite(dirPin,LOW);
}