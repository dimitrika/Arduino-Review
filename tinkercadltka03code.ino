#include <LiquidCrystal.h>

float val, valout; 
int tmp;

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

void setup()
{
  pinMode(13, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);           
  lcd.print("Suhu:");    
  lcd.setCursor(0,1);           
  lcd.print(String(tmp) + " Celcius");
}

void loop()
{
  val = analogRead(A1);
  valout = val*5000 / 1024;
  tmp = (valout-500) / 10;
  Serial.println(tmp);
  lcd.setCursor(0,1);          
  lcd.print(String(tmp) + " Celcius");
}