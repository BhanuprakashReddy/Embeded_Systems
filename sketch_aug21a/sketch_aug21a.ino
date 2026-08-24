#define switchPin 2  // The number of the pushbutton pin
const int ledPin =  3;// The number of the LED pin
int buttonState = 0;  // Variable for reading the pushbutton status

void setup() {
  // put your setup code here, to run once:

  //Initialize serial communication at 9600 bits per second:
  // Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Print the value you read to the Serial Monitor:
  Serial.println(sensorValue);
  // Delay in between reads for stability
  delay(100);

  buttonState = digitalRead(switchPin); // pushbutton state
  if(buttonState == HIGH)
  {
    // Turn LED on:
     digitalWrite(3, HIGH);
  }
  else//if(buttonState == 0)
  {
    // Turn LED off:
    digitalWrite(3, LOW);
  }
}
