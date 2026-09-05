// SPI communication b/w ESP32 and Arduino UNO

#include<SPI.h>

// SCLK (Clock)               : GPIO 18
// MISO (Master In Slave Out) : GPIO 19
// MOSI (Master Out Slave In) : GPIO 23
// CS/SS (Chip Select)        : GPIO 5

#define CLK   18
#define MISO  19
#define MOSI  23
#define CS    5

//The dedicated hardware SPI pins on an Arduino Uno are 
// SS/CS Pin: 10
// MOSI Pin : 11
// MISO Pin : 12
// SCK Pin  : 13

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  SPI.begin(CLK, MISO, MOSI, CS);
  pinMode(CS, OUTPUT);

  Serial.println("[setup] done.");  
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("[loop] ...");
  digitalWrite(CS, LOW);

  // uint8_t str = 0x43;
  // uint8_t nSent = SPI.transfer(str);

  // if(nSent > 0) {
  //   Serial.print("[loop] transfer data lenght: ");
  //   Serial.println(nSent);
  // }

  char strMsg[20] = "A";
  SPI.transfer(strMsg,  strlen(strMsg));

  digitalWrite(CS, HIGH);

  delay(4000);

}
