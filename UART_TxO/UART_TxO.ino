// ESP32 UART init
HardwareSerial uartSerial(2);

// Arduino UNO UART init
//SoftwareSerial aSerial(2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // The most common configuration in modern electronics is 8N1
  // (8 data bits, No parity, 1 stop bit).
  // Note: Arduino UNO is a Rx=10, Tx=11
  uartSerial.begin(9600, SERIAL_8N1, 16, 17); // Rx=16, Tx=17
}

void loop() {
  // put your main code here, to run repeatedly:

  //Send text to another MC

  int nSent = uartSerial.write("Hello Pavan");
  if(nSent > 0){
    Serial.print("Data sent:");
    Serial.println(nSent);
  }
  else {
    Serial.println("0 bits sent.");
  }

  delay(1000);

  if(uartSerial.available()) {
    //char recdMsg = uartSerial.read();       // Read the one byte char
    String recdMsg = uartSerial.readString(); 
    Serial.print("Received Message:");
    Serial.println(recdMsg);
  } else {
    Serial.println("There is no msg from Arduino board-MC1");
  }
}
