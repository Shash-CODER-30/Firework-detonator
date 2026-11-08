// THIS CODE HAS NOT BEEN TESTED BY THE AUTHOR. THIS IS STRICTLY AN EXPERIMENTAL PROJECT. USE THIS SOFTWARE AT YOUR OWN RISK.

#include <LiquidCrystal_I2C.h>

const int triggerbutton(12);
const int buzzer(11);

unsigned long pressTime;

LiquidCrystal_I2C lcd(0x27, 16, 2);

String securitycode("A7F3C82D"); // FEEL FREE TO CHANGE THIS CODE TO SOMETHING ELSE. IT IS RECOMMENDED TO USE A HEXADECIMAL STRING OF 8 CHARACTERS. IT MUST MATCH THE CODE ON Firework_detonator.ino.

bool prevButtonState(1);
bool currentButtonState;

void setup() {
  // SETUP CODE:
  lcd.init();
  lcd.backlight();

  pinMode(triggerbutton, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("HOLD BUTTON     ");
  lcd.setCursor(0, 1);
  lcd.print("FOR 5 SECONDS   ");
}

void loop() {
  // MAIN CODE:
  unsigned long now(millis());

  currentButtonState = digitalRead(triggerbutton);

  if(!currentButtonState) {
    if(prevButtonState) {
      pressTime = now;
      prevButtonState=currentButtonState;
    } else {
      unsigned long dt(now-pressTime);
      if(dt > 50) {
        int timeSeconds(dt/1000);
        if(timeSeconds < 5) {
          int displayTime(5-timeSeconds);
          lcd.setCursor(0, 0);
          lcd.print("HOLDING...      ");
          lcd.setCursor(0, 1);
          lcd.print(String(displayTime) + "               ");

          prevButtonState=currentButtonState;
        } else {
          currentButtonState = 1;
          prevButtonState = 1;

          digitalWrite(buzzer, HIGH);
          lcd.setCursor(0, 0);
          lcd.print("DETONATING...   ");
          lcd.setCursor(0, 1);
          lcd.print("PLEASE STAND BY ");
          Serial.println(securitycode);
          delay(6000);
          digitalWrite(buzzer, LOW);
        }
      }
    }
  } else {
    prevButtonState = 1;

    lcd.setCursor(0, 0);
    lcd.print("HOLD BUTTON     ");
    lcd.setCursor(0, 1);
    lcd.print("FOR 5 SECONDS   ");
  }
}