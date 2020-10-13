#include <Wire.h>   //Biblioteca do protocolo I2C
#include <LiquidCrystal_I2C_JHD1214.h> //Biblioteca do LCD

#define incrementa A0
#define decrementa A1
#define start A2
#define led 11
#define buzzer 13
#define cancel

 int Time = 0;

LiquidCrystal_I2C lcd(0x7C>>1, 16, 2);


void setup() 
{
   pinMode(incrementa,INPUT_PULLUP);
   pinMode(decrementa,INPUT_PULLUP);
   pinMode(start,INPUT_PULLUP);
   pinMode(led,OUTPUT);
   pinMode(buzzer,OUTPUT);
  
 lcd.clear();
 lcd.setCursor(1,0);
 lcd.print("AJUSTE O TEMPO");   
delay(200);
}

void loop() 
{ 

 if(digitalRead(incrementa)==0 && Time<99)
   {
  lcd.clear();
  Time++;
  lcd.setCursor(2,0);
  lcd.print(Time);
  delay(100);
   }

    if(digitalRead(decrementa)==0 && Time>0)
    {
  lcd.clear();
  Time--;
  lcd.setCursor(2,0);
  lcd.print(Time);
   delay(100);
   }

   if (digitalRead(start)==0){
 digitalWrite (led,1);
 bip();
      
    for(Time;Time>-1;Time--){  
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Time => ");
    lcd.print(Time);
    delay(1000);
    }
 
  digitalWrite(led,0);  
  for( int roletamacabra=0; roletamacabra<3; roletamacabra++){
    bip ();
                                                              }

  
 lcd.clear();
 lcd.setCursor(1,0);
 lcd.print("AJUSTE O TEMPO");   
delay(200);
}   
}

void bip (){
  digitalWrite(buzzer,1);
  delay(200);
  digitalWrite(buzzer,0);
  delay(200);
  }
