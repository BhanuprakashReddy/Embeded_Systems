/*************************************************
Counter implementation with help of timers
*************************************************/
#define LED_BUILTIN 2            // PIN 2 in ESP32, PIN 13 in Arduino.
#define DEFAULT_COUNTER_RESET 10  

int nCounter = 0;
int nSensorValue = DEFAULT_COUNTER_RESET;
int nSumValue = 0;
bool nFlag = false;

// Timer object initialization 
hw_timer_t *timer = NULL;

// Timer callback function
void ARDUINO_ISR_ATTR onTimer() {
  nCounter++;
  nFlag = true;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  timer = timerBegin(100000);
  if(timer == NULL){
    Serial.println("[setup] Error with the start of the timer.");
    while (1);
   }
   
  timerAttachInterrupt(timer, &onTimer);
  timerAlarm(timer, 100000, true, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(nCounter == (int)DEFAULT_COUNTER_RESET) {

    //Serial.println("Sensor sum value: ");
    //Serial.println(nSumValue);
    
    int AverageValue = nSumValue/10;
    Serial.println("Sensor average value: ");
    Serial.println(AverageValue);
    
    digitalWrite(LED_BUILTIN, HIGH);
    delay(300);
    nFlag = false;
    nCounter = 0;
    nSumValue = 0;
    nSensorValue = DEFAULT_COUNTER_RESET;
  }

  if(nFlag)
  {
    nFlag = false;
    nSumValue += nSensorValue;
    
    Serial.println("Sensor sum value: ");
    Serial.println(nSumValue);
    nSensorValue++;
    digitalWrite(LED_BUILTIN, LOW);
  }
}
