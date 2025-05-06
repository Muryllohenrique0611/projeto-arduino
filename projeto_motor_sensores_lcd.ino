#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int sensor_umi = A0;
int umi;
int sensor_temp = A1;
int temp;
int motor = 3;

void setup()
{
 
 Serial.begin(9600);
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print("MONITORAMENTO DO");
 lcd.setCursor(4,1);
 lcd.print("MORANGO");
 delay(2000);
 lcd.clear();
}

void loop()
{
  umi = map(analogRead(sensor_umi),0,879,0,100);
  temp = map(analogRead(sensor_temp),20,358,-40,125);
  
  lcd.setCursor(0,0);
  lcd.print("temperatura:"+String(temp)+"C");
  lcd.setCursor(0,1);
  lcd.print("Umidade: ");
  
  if(temp < 35){
  	
    if(umi < 30){
  		lcd.setCursor(8,1);
    	lcd.print("SECO");
    	analogWrite(motor,255);
    
  	}else if(umi < 50){
    	lcd.setCursor(8,1);
    	lcd.print("BAIXO");
    	analogWrite(motor,150);
  	
    }else if(umi < 75){
  		lcd.setCursor(8,1);
    	lcd.print("MEDIO");
    	analogWrite(motor,100);
  	
     }else{
  		lcd.setCursor(8,1);
    	lcd.print("ALTO");
    	analogWrite(motor,0);
  	}
  }else{
    lcd.setCursor(0,1);
    lcd.print("TEMPERATURA ALTA");
    analogWrite(motor,0);
  }
  delay(500);
  lcd.clear();
}