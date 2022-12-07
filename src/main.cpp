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
//################################
const int StepX = A3; // X.STEP
const int DirX = A4;  // X.DIR
//########################################
int pulseWidthMicros = 1000;  // microseconds
int millisBtwnSteps = 15000;

//############## sensors
void CheckCap();
void CheckBottol();
void InitialPositionSet();

//############# motors
void ConvMotor(boolean status);
void CircleRotorStepper(int x);
void CapSetMotor(boolean status);

//############# pumps
void FillPump(boolean status);
void CapSetPump(boolean status);
void setup() {

  pinMode(ir_fill, INPUT);
  pinMode(ir_start, INPUT);
  pinMode(ir_CAP, INPUT);
  pinMode(air_pump, OUTPUT);
  pinMode(motor_conv, OUTPUT);
  pinMode(pump_filling, OUTPUT);
  pinMode(motor_cap, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  pinMode(en_stepper, OUTPUT);
  Serial.begin(9600);

   // set up the LCD's number of columns and rows:
  lcd.begin(20,4);
  // Print a message to the LCD.
  lcd.print("fILLING PROJECT!");
  
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