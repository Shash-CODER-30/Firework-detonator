// THIS CODE HAS NOT BEEN TESTED BY THE AUTHOR. THIS IS STRICTLY AN EXPERIMENTAL PROJECT. USE THIS SOFTWARE AT YOUR OWN RISK.

const int detonator(12);
const int ledRed(11);
const int ledGreen(10);
const int buzzer(9);

String securitycode(0xA7F3C82D); // FEEL FREE TO CHANGE THIS CODE TO SOMETHING ELSE. IT IS RECOMMENDED TO USE A HEXADECIMAL STRING OF 8 CHARACTERS. IT MUST MATCH THE CODE ON Firework_detonator_controller.ino.

void setup() {
  // SETUP CODE:
  Serial.begin(9600);

  pinMode(detonator, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(ledGreen, HIGH);
}

void loop() {
  // MAIN CODE:
  if(Serial.available()) {
    String message(Serial.readStringUntil('\n'));

    if(message == securitycode) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      digitalWrite(detonator, HIGH);
      delay(5000);
      digitalWrite(detonator, LOW);
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, HIGH);
      digitalWrite(buzzer, LOW);
    }
  }
}