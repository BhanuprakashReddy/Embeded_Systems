//Find the Timers break even point

int nTimer1Counter = 0, nTimer2Counter = 0, nTimer3Counter = 0,
    nTimer4Counter = 0, nTimer5Counter = 0;

// Timer objects initialization
hw_timer_t *timer1 = NULL, *timer2 = NULL, *timer3 = NULL,
           *timer4 = NULL, *timer5 = NULL;

// Timer callback function
void ARDUINO_ISR_ATTR onTimer1() {
  nTimer1Counter++;
}


void ARDUINO_ISR_ATTR onTimer2() {
  nTimer2Counter++;
}


void ARDUINO_ISR_ATTR onTimer3() {
  nTimer3Counter++;
}

void ARDUINO_ISR_ATTR onTimer4() {
  nTimer4Counter++;
}


void ARDUINO_ISR_ATTR onTimer5() {
  nTimer5Counter++;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //Timer - 1
  timer1 = timerBegin(100000);
  if(timer1 == NULL){
    Serial.println("[setup] Error with the start of the timer-1");
    while (1);
  }
  timerAttachInterrupt(timer1, & onTimer1);
  timerAlarm(timer1, 100000, true, 0);

  //Timer - 2
  timer2 = timerBegin(100000);
  if(timer2 == NULL){
    Serial.println("[setup] Error with the start of the timer-2");
    while (1);
  }
  timerAttachInterrupt(timer2, & onTimer2);
  timerAlarm(timer2, 100000, true, 0);

  //Timer - 3
  timer3 = timerBegin(100000);
  if(timer3 == NULL){
    Serial.println("[setup] Error with the start of the timer-3");
    while (1);
  }
  timerAttachInterrupt(timer3, & onTimer3);
  timerAlarm(timer3, 100000, true, 0);

  //Timer - 4
  timer4 = timerBegin(100000);
  if(timer4 == NULL){
    Serial.println("[setup] Error with the start of the timer-4");
    while (1);
  }
  timerAttachInterrupt(timer4, & onTimer4);
  timerAlarm(timer4, 100000, true, 0);

  // //Timer - 5
  // timer5 = timerBegin(100000);
  // if(timer5 == NULL){
  //   Serial.println("[setup] Error with the start of the timer-5");
  //   while (1);
  // }
  // timerAttachInterrupt(timer5, & onTimer5);
  // timerAlarm(timer5, 100000, true, 0);

  Serial.println("[setup] timers started.");
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("[loop] ...");

  Serial.print("[loop] First timer counter value: ");
  Serial.println(nTimer1Counter);
  Serial.print("[loop] Second timer counter value: ");
  Serial.println(nTimer2Counter);
  Serial.print("[loop] Third timer counter value: ");
  Serial.println(nTimer3Counter);
  Serial.print("[loop] Fourth timer counter value: ");
  Serial.println(nTimer4Counter);

  // Serial.print("[loop] Fifth timer counter value: ");
  // Serial.println(nTimer5Counter);
  delay(1000);
}
