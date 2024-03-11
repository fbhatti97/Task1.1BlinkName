// Define pin numbers
const int buttonPin = 2;
const int ledPin = 13;

// Morse code timings
const int dotTime = 300;
const int dashTime = 800;
const int partGap = 300; // Gap between dots and dashes of the same letter
const int letterGap = 900; // Gap between letters
const int wordGap = 1400; // Gap between words

// Variable to keep track of the button press state
bool isButtonPressed = false;

// Setup function to initialize the pin modes
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

// Function to blink a dot
void blinkDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotTime);
  digitalWrite(ledPin, LOW);
  delay(partGap);
}

// Function to blink a dash
void blinkDash() {
  digitalWrite(ledPin, HIGH);
  delay(dashTime);
  digitalWrite(ledPin, LOW);
  delay(partGap);
}

// Function to spell a letter in Morse code
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
    // Add more cases for other letters as needed
  }
  delay(letterGap); // Gap between letters
}

// Loop function that waits for a button press to start the blinking
void loop() {
  // Check if the button is pressed
  if (digitalRead(buttonPin) == HIGH && !isButtonPressed) {
    isButtonPressed = true; // Mark the button as pressed

    // Spell out the name
    spellLetter('F');
    spellLetter('A');
    spellLetter('Y');
    spellLetter('S');
    spellLetter('A');
    spellLetter('L');

    // After spelling the name, wait for the button to be released
    while(digitalRead(buttonPin) == HIGH) {
      // Do nothing, just wait
    }
    isButtonPressed = false; // Reset the button press state
  }
}
