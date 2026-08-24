
#define BOARD_LED_PIN 13

int buttonState =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(BOARD_LED_PIN, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  
  // Delay in between reads for stability
  delay(100);
}
