
bool timerFlag = false;
hw_timer_t * timer = NULL;

//hw_timer_t * timerBegin(uint32_t frequency);

// function call by the timer interruption
void IRAM_ATTR onTimer() {
    timerFlag = true;
}

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(115200); // 9600 -> 115200
  Serial.println("[setup] Start...");
  
  // Timer initialisation at a frequency of 1 MHz (1 µs per tick)
  timer = timerBegin(100000);
  
  if (timer == NULL) {
    Serial.println("[setup] Error with the start of the timer");
    while (1);
  }
  
  // Attaches the interrupt function to the timer
  timerAttachInterrupt(timer, &onTimer);

  // Start of the timer
  timerAlarm(timer, 100000, true);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(timerFlag == true){
    timerFlag = false;
    Serial.println("[loop]", timerFlag);
    
  }
  
}
