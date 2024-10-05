// Pin where the button is connected
const int buttonPin = 2;
int buttonState = 0;

void setup() {
    // Initialize the digital pin as input with internal pull-up resistor
    pinMode(buttonPin, INPUT_PULLUP);
    
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
    // Read the state of the button
    buttonState = digitalRead(buttonPin);

    // If the button is pressed (active-low logic)
    if (buttonState == LOW) {
        // Send a message via Serial (to the PC)
        Serial.println("Button Pressed");
        // Add a short delay to debounce the button
        delay(200);
    }
}
