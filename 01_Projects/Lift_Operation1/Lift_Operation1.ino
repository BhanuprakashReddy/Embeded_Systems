
#define OUTSIDE_F0_INPUT_UP   1
#define OUTSIDE_F0_INPUT_DOWN 2

#define OUTSIDE_F1_INPUT_UP   3
#define OUTSIDE_F1_INPUT_DOWN 4

#define OUTSIDE_F2_INPUT_UP   5
#define OUTSIDE_F2_INPUT_DOWN 6

#define OUTSIDE_F3_INPUT_UP   7
#define OUTSIDE_F3_INPUT_DOWN 8

#define INSIDE_INPUT_0        9
#define INSIDE_INPUT_1        10
#define INSIDE_INPUT_2        11
#define INSIDE_INPUT_3        12

#define LED_DST_REACHED       13
#define LED_ERROR             14

enum ElevatorState {
  IDLE,
  MOVING,
  STOP
};

ElevatorState currentState  = IDLE;
short int currenPosition    = 0;
short int targetPosition    = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(OUTSIDE_F0_INPUT_UP,    INPUT);
  pinMode(OUTSIDE_F0_INPUT_DOWN,  INPUT);
  pinMode(OUTSIDE_F1_INPUT_UP,    INPUT);
  pinMode(OUTSIDE_F1_INPUT_DOWN,  INPUT);
  pinMode(OUTSIDE_F2_INPUT_UP,    INPUT);
  pinMode(OUTSIDE_F2_INPUT_DOWN,  INPUT);
  pinMode(OUTSIDE_F3_INPUT_UP,    INPUT);
  pinMode(OUTSIDE_F3_INPUT_DOWN,  INPUT);

  pinMode(INSIDE_INPUT_0,  INPUT);
  pinMode(INSIDE_INPUT_1,  INPUT);
  pinMode(INSIDE_INPUT_2,  INPUT);
  pinMode(INSIDE_INPUT_3,  INPUT);
  
  pinMode(LED_DST_REACHED,   OUTPUT);
  pinMode(LED_ERROR, OUTPUT);

  Serial.println("[setup] Done.");
}

void loop() {
  // put your main code here, to run repeatedly:

  int userPress1 = 0, userPress2 = 0 , userPress3 = 3;
  userPress1 = digitalRead(INSIDE_INPUT_1);
  userPress2 = digitalRead(INSIDE_INPUT_2);
  userPress3 = digitalRead(INSIDE_INPUT_3);

  if(currenPosition == 0) 
  {
      if(userPress1 == 1) {
        targetPosition = 1;
        Serial.println("[loop] User pressed 1.");
      }        
      else if(userPress2 == 1)
      {
        targetPosition = 2;
        Serial.println("[loop] User pressed 2.");
      }       
      else if(userPress3 == 1)
      {
        targetPosition = 3;
        Serial.println("[loop] User pressed 3.");
      }
      else
      {
        Serial.println("[loop] User not pressed any key.");
      }
  }

  if(currenPosition == 1) 
  {
    if(userPress0 == 1) {
        targetPosition = 0;
        Serial.println("[loop] User pressed 0.");
      }        
      else if(userPress2 == 1)
      {
        targetPosition = 2;
        Serial.println("[loop] User pressed 2.");
      }       
      else if(userPress3 == 1)
      {
        targetPosition = 3;
        Serial.println("[loop] User pressed 3.");
      }
      else
      {
        Serial.println("[loop] User not pressed any key.");
      }    
  }

  if(currenPosition == 2)
  {
    if(userPress0 == 1) {
        targetPosition = 0;
        Serial.println("[loop] User pressed 0.");
      }        
      else if(userPress1 == 1)
      {
        targetPosition = 1;
        Serial.println("[loop] User pressed 1.");
      }       
      else if(userPress3 == 1)
      {
        targetPosition = 3;
        Serial.println("[loop] User pressed 3.");
      }
      else
      {
        Serial.println("[loop] User not pressed any key.");
      }
  }

  if(currenPosition == 3) 
  {
    if(userPress0 == 1) {
        targetPosition = 0;
        Serial.println("[loop] User pressed 0.");
      }        
      else if(userPress1 == 1)
      {
        targetPosition = 1;
        Serial.println("[loop] User pressed 1.");
      }       
      else if(userPress2 == 1)
      {
        targetPosition = 2;
        Serial.println("[loop] User pressed 2.");
      }
      else
      {
        Serial.println("[loop] User not pressed any key.");
      }
  }

  if(targetPosition != currenPosition)
  {
    Serial.println("[loop] Elevator moving ...");
    delay(100);
    digitalWrite(LED_DST_REACHED, HIGH);
    delay(1000);
    currenPosition = targetPosition;
  }
  
}
