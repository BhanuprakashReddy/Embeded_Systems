//////////////////////////////////////////////////////////////////////////
// milli() method implementation                                        //
// The millis() function in Arduino returns the number of milliseconds  // 
// elapsed since the board began running the current sketch.            //
//////////////////////////////////////////////////////////////////////////

#define LED_BUILTIN 2

// Define the time interval (e.g., 1 second = 1000 milliseconds)
const unsigned long interval = 1000;

// Variable to store the last time the action triggered
unsigned long previousMillis = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Get the current snapshot of time
  unsigned long currentMillis = millis(); 

  // Check if the required interval has passed
  if (currentMillis - previousMillis >= interval) {
    // Save the last time you blinked the LED
    previousMillis = currentMillis; 

    // Perform your action (Toggle the LED state)
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
  
  // Any code written out here runs instantly without waiting for the timer!

}
