#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

#define GAS_SENSOR_PIN A0 
#define GAS_THRESHOLD 500 // Nilai ambang batas untuk sensor gas MQ-2

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
    lcd.init();
    lcd.backlight();
}

void loop() {
    int gasValue = analogRead(GAS_SENSOR_PIN); 
    lcd.clear(); 
    lcd.setCursor(0, 0);
    lcd.print("Sensor Gas:");

    // Tampilkan nilai sensor gas
    lcd.setCursor(11, 0); 
    lcd.print(gasValue);

    
    lcd.setCursor(0, 1);
    if (gasValue > GAS_THRESHOLD) {
        lcd.print("Terdeteksi");
    } else {
        lcd.print("Tidak terdeteksi");
    }

    delay(1000); 
}
