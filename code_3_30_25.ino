#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_7segment matrix = Adafruit_7segment(); // Create the 7-segment object

// Define the message to scroll
String message = "HI MY NAME IS MAYUMI";  
int messageLength;

void setup() {
  matrix.begin(); // Initialize the display
  matrix.setBrightness(15);  // Set the brightness to maximum (0-15)

  messageLength = message.length(); // Get the length of the message
}

void loop() {
  // Continuously scroll the message
  for (int i = 0; i < messageLength + 4; i++) { 
    matrix.clear(); // Clear the display each time before writing new characters
    
    // Display characters based on the scroll position
    for (int j = 0; j < 4; j++) {
      int charIndex = i + j; // Determine the character index for each digit
      
      // Only show characters from the message, else leave it empty
      if (charIndex < messageLength) {
        matrix.writeDigitAscii(j, message.charAt(charIndex)); // Write each character on the corresponding digit
      } else {
        matrix.writeDigitAscii(j, ' '); // Blank out the extra digits
      }
    }
    
    matrix.writeDisplay(); // Update the display
    delay(300); // Delay to control the scroll speed
  }

  // Reset the message to start from the beginning after one complete loop
  // No need to do anything special since the loop will naturally continue to scroll again
}