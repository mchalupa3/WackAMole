
#include <LiquidCrystal.h>
// digitalWrite(pin, high/low) output
// digitalRead(pin, high/low) input

// Initializes the Button Pins
int buttons[] = {2,3,4,5};

// Initializes the LED Pins
int leds[] = {10,11,12,13};

int score = 0;

LiquidCrystal lcd(0, 1, 6, 7, 8, 9);

void setup() {
  // Sets up input
  for (int button : buttons) {
    pinMode(button, INPUT);
  }
  // Sets up the output
  for (int led : leds) {
    pinMode(led, OUTPUT);
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
  }
  lcd.begin(16, 2);
  String scorestring = String(score);
  lcd.print("Score:" + scorestring );
}

void loop() {
 

  for (int led:leds) {
    digitalWrite(led,LOW);
  }
  
  // get random number
  int chosenLED = random(0,4);

  digitalWrite(leds[chosenLED],HIGH);

  int selected = 5;
  while (selected > 3) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttons[i]) == HIGH) {
        selected = i;
        break;
      }
    }
  }
  
  if (chosenLED != selected) {
    digitalWrite(chosenLED,LOW);
    wrong();
  } else {
    right();
    
  }
}

boolean selectedButton() {
  for (int button:buttons) {
    if (digitalRead(button) == HIGH)
      return true;
  }
  return false;
}

int randomNum(int min, int max) {
  return random(min,max);
}

void right() {
  score += 1;
  lcd.clear();
    String scorestring = String(score);

   lcd.print("Score:" + scorestring );

  for (int i = 0; i < 3; i++) {
    for (int led:leds) {
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(led,LOW);
      
    }

    for (int i = 3; i >= 0; i--) {
      digitalWrite(leds[i],HIGH);
      delay(100);
      digitalWrite(leds[i],LOW);
    }
  }
}

void wrong() {
  score = 0;
  lcd.clear();
  String scorestring = String(score);

  lcd.print("Score:" + scorestring);
  for (int i = 0; i < 3; i++) {
    for (int led:leds) {
      digitalWrite(led,HIGH);
    }
    delay(500);
    for (int led:leds) {
      digitalWrite(led,LOW);
    }
    delay(500);
  }
}

