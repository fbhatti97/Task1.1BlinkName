// Define pin numbers
const int buttonPin = 2;
const int ledPin = 13;

// Morse code timings
const int dotTime = 300;
const int dashTime = 800;
const int partGap = 350; // Gap between dots and dashes of the same letter
const int letterGap = 900; 
const int wordGap = 1400; 

// Keep track of the button press state
bool isButtonPressed = false;


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void blinkDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotTime);
  digitalWrite(ledPin, LOW);
  delay(partGap);
}

void blinkDash() {
  digitalWrite(ledPin, HIGH);
  delay(dashTime);
  digitalWrite(ledPin, LOW);
  delay(partGap);
}

void spellLetter(char letter) {
  switch (letter) {
    case 'F':
      blinkDot(); blinkDot(); blinkDash(); blinkDot();
      break;
    case 'A':
      blinkDot(); blinkDash();
      break;
    case 'Y':
      blinkDash(); blinkDot(); blinkDash(); blinkDash();
      break;
    case 'S':
      blinkDot(); blinkDot(); blinkDot();
      break;
    case 'L':
      blinkDot(); blinkDash(); blinkDot(); blinkDot();
      break;
    
  }
  delay(letterGap); 
}


void loop() {
  
  if (digitalRead(buttonPin) == HIGH && !isButtonPressed) {
    isButtonPressed = true; 

    spellLetter('F');
    spellLetter('A');
    spellLetter('Y');
    spellLetter('S');
    spellLetter('A');
    spellLetter('L');


    while(digitalRead(buttonPin) == HIGH) {

    }
    isButtonPressed = false; // Reset the button press state
  }
}
