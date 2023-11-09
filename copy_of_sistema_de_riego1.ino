#include <LiquidCrystal.h>

LiquidCrystal lcd(10,11,12,9,8,7,6);

int motor1=5;
int motor2=3;
float temp=0;
int LedRojo=2;

void setup()
{
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear(); 
}

void loop()
{
  int humedad=analogRead(A0);
  float valor=analogRead(A1);
  float ldr = analogRead(A2);

  temp=(((5*valor*100)/1024)-50);

  Serial.println("La humedad es:");
  Serial.println(humedad);
  Serial.println("La temperatura es:");
  Serial.println(temp);
  Serial.println("LUZ:");
  Serial.println(ldr);
  
  if (humedad<=700)
  {
   digitalWrite(motor1,HIGH);
  }else if(humedad>700)
  {
   digitalWrite(motor1,LOW);
  }
  
  if (temp>=30)
  {
   digitalWrite(motor2,HIGH);
  }else if(temp<30)
  {
   digitalWrite(motor2,LOW);
  }
  
  if(ldr <=700)
  {
    digitalWrite(LedRojo,LOW);
  
  }else if (ldr>700)
  {
    digitalWrite(LedRojo,HIGH);
  }

lcd.setCursor(0, 0);

lcd.print("Temp:");
lcd.print(temp);
lcd.print(" C");

lcd.setCursor(0, 1);
lcd.print("Luz:");
lcd.print(ldr);
  
delay(2500);
lcd.clear();
delay(500);

lcd.setCursor(0, 0);
lcd.print("Hum: ");
lcd.print(humedad);

lcd.setCursor(0,1);

if(humedad<=200){
lcd.print("Muy seco");
}
else if(humedad>200 && humedad <= 400){
lcd.print("Seco");
}
else if(humedad>400 && humedad <= 600){
lcd.print("Humedo");
}
else if(humedad>600){
lcd.print("Muy humedo");
}

delay(1000);
lcd.clear();
delay(500);

}