#include<LiquidCrystal.h>

// LCD PINS*****************
const int rs = A5, en = A6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//--------------------------------------------

//RELAY PINS************
int air_pump = 12;
int motor_conv = 11;
int pump_filling = 10;
int motor_cap = 9;
//------------------------------------------

//IR SENSOR PINS**************
int ir_start = 8;
int ir_fill = 6;
int ir_CAP = 7;
//-----------------------------------------

//BUZZER PIN**********************
int buz = A2;
//------------------------------------------

//STEPPER MOTOR PINS********************
const int StepX = A3;
const int DirX = A4;
int pulseWidthMicros = 1000;  // microseconds
int millisBtwnSteps = 15000;
void translationX (uint8_t pin1, uint8_t pin2,int stepsPerRev1){
  digitalWrite(StepX, pin1); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int i = 0; i < stepsPerRev1; i++) {
    digitalWrite(StepX, pin1);
    delayMicroseconds(pulseWidthMicros);
    digitalWrite(StepX, pin2);
    delayMicroseconds(millisBtwnSteps);
  }
}//------------------------------------------
void setup(){

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
  Serial.begin(9600);

   // set up the LCD's number of columns and rows:
  lcd.begin(20,4);
  // Print a message to the LCD.
  lcd.print("fILLING PROJECT!");

}


void loop(){



  


    // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);



   while(1)
  {
     int ir_start_State = digitalRead (ir_start);
      Serial.println(ir_start_State);
    while( ir_start_State == HIGH)
    {
       
       digitalWrite(motor_conv,HIGH);
       delay(1000);
       digitalWrite(motor_conv,LOW);
       delay(100);
        translationX(LOW,HIGH,50); // spin the disc

      if (digitalRead(ir_start)== LOW)
      break;
       
      }

       if(digitalRead (ir_fill) == HIGH )
  {
    
    
    digitalWrite(pump_filling, HIGH);
    delay(2200);
    digitalWrite(pump_filling, LOW);
    delay(1100);
    //digitalWrite(buz, HIGH);
    translationX(LOW,HIGH,50); // spin the disc
    
    digitalWrite(air_pump, HIGH);
    delay(2000);
    digitalWrite(air_pump, LOW);
    delay(2000);
    digitalWrite(motor_cap, HIGH);
    delay(2000);
    digitalWrite(motor_cap, LOW);
    translationX(LOW,HIGH,50); // spin the disc


      
  if(digitalRead (ir_CAP) == 1)
  {
    
    
    translationX(LOW,HIGH,50); // spin the disc
    
  }

  }} }
   
  /* int ir_start_State = digitalRead (ir_start);
   
//Serial.println(ir_start_State);
  //   if(ir_start_State == 1)
  {
    digitalWrite(motor_conv, HIGH);
    delay(1000);
    digitalWrite(motor_conv, LOW);
    
   // translationX(HIGH,LOW,50); // spin the disc
    // digitalWrite(buz, HIGH);
    
  }
   if(ir_start_State == 0)
  {
    digitalWrite(motor_conv, LOW);
   // translationX(HIGH,LOW,50); // spin the disc
    // digitalWrite(buz, HIGH);
     
    
  }*/
