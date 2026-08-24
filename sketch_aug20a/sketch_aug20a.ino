//#define LED 2 // Configured in digitalPin
#define LED 13  //->LED which is integrated in Arduino UNO board.
int count;

void setup() {
  // put your setup code here, to run once:

  // Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Serial.print("loop");
  for (int i= 0; i < 100; i++)
  {
    // For even numbers glows the LED which is integrated in Arduino UNO board.
    if( i%2 == 0)
    {
      digitalWrite(LED, HIGH);
      delay(1000);
      digitalWrite(LED, LOW);
      delay(1000);
    }
    
    // For odd numbers LED glow on bread board.
    if( i%2 != 0)
    {
      digitalWrite(2, HIGH);
      delay(1000);
      digitalWrite(2, LOW);
      delay(5000);
    }
  }
}
