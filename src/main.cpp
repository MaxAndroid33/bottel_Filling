#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

// Initialise the LCD with the arduino. LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(A4, A5, 3, 2, 4, 5);

//--------------------------------------------

// RELAY PINS************
#define air_pump 11
#define motor_conv 12
#define pump_filling 10
#define motor_cap 9

//------------------------------------------

// IR SENSOR PINS**************
#define ir_start 8
#define ir_fill 6
#define ir_CAP 7
//-----------------------------------------

// BUZZER PIN**********************
#define buz A2
//------------------------------------------

// STEPPER MOTOR PINS********************
#define en_stepper 13
// ################################
const int StepX = A3; // X.STEP
// const int DirX = A4;  // X.DIR
const int speedStepper = 7000;
// ########################################
const int CappingTime = 5000;
const int fillingTime = 2000;

// ############## sensors
void CheckCap();
void CheckBottol();
void InitialPositionSet();
void buzz(int mode);
// ############# motors
void ConvMotor(boolean status);
void CircleRotorStepper(int x);
void CapSetMotor(boolean status);

// ############# pumps
void FillPump();
void CapSetPump();


void setup()
{

  pinMode(ir_fill, INPUT);
  pinMode(ir_start, INPUT);
  pinMode(ir_CAP, INPUT);
  pinMode(air_pump, OUTPUT);
  pinMode(motor_conv, OUTPUT);
  pinMode(pump_filling, OUTPUT);
  pinMode(motor_cap, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(StepX, OUTPUT);
  pinMode(en_stepper, OUTPUT);
  Serial.begin(9600);

  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print("fILLING PROJECT!");
  Serial.begin(9600);
}

void loop()
{
  buzz(2);
  // InitialPositionSet();
 
  
  // CheckBottol();
  // FillPump();
  CheckCap();
  CapSetPump();

  // ConvMotor(true);
  // delay(2000);
  // ConvMotor(false);
  // delay(2000);
  
}

void buzz(int mode)
{
  if(mode ==1){
    digitalWrite(buz, HIGH);
  delay(1000);
  digitalWrite(buz, LOW);
  }
  else if (mode ==2)
  {
   digitalWrite(buz, HIGH);
  delay(100);
  digitalWrite(buz, LOW);
delay(100);
  digitalWrite(buz, HIGH);
  delay(100);
  digitalWrite(buz, LOW);
  }
  
 
}


void InitialPositionSet()
{ 
  while (digitalRead(ir_start))
  {
    CircleRotorStepper(1);
  }

  CircleRotorStepper(0);
 ConvMotor(true);
 delay(2000);
 ConvMotor(false);
 
   buzz(1);
  
 
}


void CircleRotorStepper(int x)
{
  if (x == 1)
  {
    digitalWrite(en_stepper, LOW);
    // digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
    // Makes 200 pulses for making one full cycle rotation
    digitalWrite(StepX, LOW);
    delayMicroseconds(speedStepper);
    digitalWrite(StepX, HIGH);
    delayMicroseconds(speedStepper);
  }
  if (x == 0)
    digitalWrite(en_stepper, HIGH); // digitalWrite(dirPin,LOW);
}


void CheckBottol()
{
  while (digitalRead(ir_fill)){
    CircleRotorStepper(1);
  }

  CircleRotorStepper(0);

  buzz(1);
}


void FillPump()
{
  digitalWrite(pump_filling, HIGH);
  buzz(1);
  delay(fillingTime);
  digitalWrite(pump_filling, LOW);
  buzz(1);
  CircleRotorStepper(1);
}
void CheckCap(){

while(digitalRead(ir_CAP)){
  CircleRotorStepper(1);
}

  CircleRotorStepper(0);

  buzz(2);

}

void CapSetPump(){
  CapSetMotor(true);
 digitalWrite(air_pump, HIGH);
  buzz(1);
  delay(CappingTime);
  digitalWrite(air_pump, LOW);
  buzz(1);
  CapSetMotor(false);
}

void ConvMotor(boolean status){

  if (status)
    digitalWrite(motor_conv, HIGH);
  else if (!status)
  {
    digitalWrite(motor_conv, LOW);
  }
  
    
}

void CapSetMotor(boolean status){

  if (status == true)
    digitalWrite(motor_cap, HIGH);
  else
    digitalWrite(motor_cap, LOW);
}