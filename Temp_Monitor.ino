#include <LiquidCrystal_I2C.h>

#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN A3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); 


int humidity;
int temp;

void setup(){
Serial.begin(9600);
lcd.begin();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("Temp , Humidity");
lcd.setCursor(0,1);
lcd.print("    Test");
delay(5000);
lcd.clear();
dht.begin();
}


void loop(){
humidity = dht.readHumidity();
temp = dht.readTemperature();
lcd.setCursor(0,0);
lcd.print("Humidity: ");
lcd.print("%");
lcd.print(humidity);
lcd.setCursor(0,1);
lcd.print("Temp: ");
lcd.print(temp);
lcd.print(" Celsius");
delay(1000);
 }

