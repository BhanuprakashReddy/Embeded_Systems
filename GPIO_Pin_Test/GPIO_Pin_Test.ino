// GPIO's Pin test in ESP32 

#define LED_BUILTIN       2
#define LED_RED_BB        15

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_RED_BB, OUTPUT);
  
  Serial.println("[setup] ...");
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("[loop] ...");

  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  digitalWrite(LED_RED_BB, !digitalRead(LED_RED_BB));
  delay(1000);
}
