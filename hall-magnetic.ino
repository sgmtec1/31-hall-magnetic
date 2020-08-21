// Open Source
// KY-024 HALL MAGNETIC - 44E

#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int sensorPin = A0; // Declaration of the input pin
 
// Serial OUT in 9600 baud
void setup()
{
    Serial.begin(9600);
    lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
    lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
}
 
// The program measures the current voltage at the sensor,
// calculates the resistance with it and a known resistor
// and outputs it via serial OUT
 
void loop()
{      
        // Measuring of the current voltage...
        int rawValue = analogRead(sensorPin);
        float voltage = rawValue * (5.0/1023) * 1000;
        float resitance = 10000 * ( voltage / ( 5000.0 - voltage) );
         
    // ... output via serial interface
    Serial.print("Tensão");   Serial.print(voltage); Serial.print("mV");
    Serial.print(", Resistance:"); Serial.print(resitance); Serial.println("Ohm");
    Serial.println("---------------------------------------");

    lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
    lcd.print("TENSAO: ");
    lcd.print(voltage);
    lcd.print(" mV");
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("RESI: ");
    lcd.print(resitance);
    lcd.print(" Ohm");
    delay(500);
}
