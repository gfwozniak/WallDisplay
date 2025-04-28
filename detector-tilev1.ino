// Define the analog input pins
const int analogPins[] = {A1, A2, A3, A10};
const int numPins = sizeof(analogPins) / sizeof(analogPins[0]);

// Define the PWM output pin
const int pwmPin = D9;

// Set the max analog value based on 10-bit ADC (0-1023) or 12-bit (0-4095)
const int analogMax = 1023; // Adjust to 4095 if using a board with 12-bit ADC

void setup() {
  // Set PWM pin as output
  pinMode(pwmPin, OUTPUT);
  // Optional: Begin serial for debugging
  Serial.begin(9600);
}

void loop() {
  int maxVal = 0;

  // Read each analog pin and find the maximum value
  for (int i = 0; i < numPins; i++) {
    int val = analogRead(analogPins[i]);
    if (val > maxVal) {
      maxVal = val;
    }
  }
  if (maxVal < 40) {
    maxVal = 0;
  }
  if (maxVal > 1010) {
    maxVal = analogMax;
  }

  // Map the maximum analog value to a PWM range (0-255)
  int pwmValue = map(maxVal, 0, analogMax, 0, 255);
  analogWrite(pwmPin, pwmValue);

  // Debug output (optional)
  Serial.print("Max analog value: ");
  Serial.print(maxVal);
  Serial.print(" -> PWM: ");
  Serial.println(pwmValue);

  delay(100); // Short delay for stability
}
