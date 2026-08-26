
bool timerFlag = false;
hw_timer_t * timer = NULL;

#define LED_PIN 2

//hw_timer_t * timerBegin(uint32_t frequency);
// function call by the timer interruption
// void IRAM_ATTR onTimer()
// void ARDUINO_ISR_ATTR onTimer()

void ARDUINO_ISR_ATTR onTimer() { 
    timerFlag = true;
}

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(115200); // baud rate: 9600 -> 115200
  Serial.println("[setup] Start...");

  pinMode(LED_PIN, OUTPUT);
  
  // Timer initialisation at a frequency of 1 MHz (1 µs per tick)
  timer = timerBegin(100000);
  
  if (timer == NULL) {
    Serial.println("[setup] Error with the start of the timer");
    while (1);
  }
  
  // Attaches the interrupt function to the timer
  timerAttachInterrupt(timer, &onTimer);

  // Start of the timer
  timerAlarm(timer, 100000, true, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(timerFlag == true){
    Serial.print("[loop] timerFlage: ");
    Serial.println(timerFlag);

    digitalWrite(LED_PIN, HIGH);
    delay(500);
    timerFlag = false;
       
    // Formatting numbers
    //Serial.println(75, BIN);     // Outputs: 1001011
    //Serial.println(12.3456, 3);  // Outputs: 12.346 (rounds to 3 decimal places)
  }else {
    digitalWrite(LED_PIN, LOW);
    //delay(1000);
    Serial.println("[loop] timerFlage not updated in timer callback.");
  }
}
