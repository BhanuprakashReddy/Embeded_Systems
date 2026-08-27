
#define LED_UP_ARROW    1
#define LED_DOWN_ARROW  2
#define LED_BUILTIN     13

enum ElevatorState {
  IDLE,
  MOVING,
  DOOR_OPEN
};

ElevatorState currentState = IDLE;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("[setup] ...");
}

void loop() {
  // put your main code here, to run repeatedly:

  

}
