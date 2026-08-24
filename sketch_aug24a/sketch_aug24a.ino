#define LED_PIN       8
#define BOARD_LED_PIN 13
#define BUTTON_PIN    5

int buttonState =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BOARD_LED_PIN, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState = digitalRead(BUTTON_PIN);
  Serial.println(buttonState);
  
  if(buttonState == 1) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BOARD_LED_PIN, HIGH);
  }else {
    
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BOARD_LED_PIN, LOW);
  }  
}
