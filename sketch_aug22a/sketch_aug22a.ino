
#include<esp_efuse.h>
#include<esp_system.h.>

void setup() {
  // put your setup code here, to run once:

   Serial.begin(115200); // 4800, 9600, 115200
   while (!Serial);


   uint8_t base_mac[6];
  esp_read_mac(base_mac, ESP_MAC_WIFI_STA);
  char uniqueId[18];
  sprintf(uniqueId, "%02X:%02X:%02X:%02X:%02X:%02X", 
  base_mac[0], base_mac[1], base_mac[2], 
  base_mac[3], base_mac[4], base_mac[5]);
  Serial.println(uniqueId);

  // Print the value of device Id:
  //String deviceId = getDeviceUniqueIdStr();
  //Serial.print("Device Unique ID: ");
  //Serial.println(deviceId);
  
  uint64_t chipId = ESP.getEfuseMac();
  char uniqueId[23];
  snprintf(uniqueId, sizeof(uniqueId), "ESP32-%04llX%08llX", (uint16_t)(chipId >> 32), (uint32_t)chipId);
  Serial.println(uniqueId);
}

void loop() {
  // put your main code here, to run repeatedly:

}
