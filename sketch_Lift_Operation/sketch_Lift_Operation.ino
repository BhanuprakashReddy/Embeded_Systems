
#define LED_UP_ARROW    1
#define LED_DOWN_ARROW  2
#define USER_INPUT      3
#define LED_IN_BOARD    13

enum ElevatorState {
  IDLE,
  MOVING,
  DOOR_OPEN
};

ElevatorState currentState  = IDLE;
short int currenPosition    = 0;
short int targetPosition    = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(USER_INPUT,     INPUT);
  pinMode(LED_UP_ARROW,   OUTPUT);
  pinMode(LED_DOWN_ARROW, OUTPUT);
  pinMode(LED_IN_BOARD,   OUTPUT);
    
  Serial.println("[setup] Done.");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  targetPosition = digitalRead(USER_INPUT);
  if(targetPosition != currenPosition){
    if(targetPosition > currenPosition){
      digitalWrite(LED_UP_ARROW, HIGH);
      digitalWrite(LED_DOWN_ARROW, LOW);
    }
    else{targetPosition < currenPosition)
      digitalWrite(LED_DOWN_ARROW, HIGH);
      digitalWrite(LED_UP_ARROW, LOW);
    }
    currenPosition = targetPosition;
  }
}
