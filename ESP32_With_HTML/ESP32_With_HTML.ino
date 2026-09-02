
#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

WebServer server(80);

// HTML content stored in flash memory
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
  <html>
    <head>
      <title>ESP32 Web Server</title>
      <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>  
    <body>
      <h1>Hello from ESP32!</h1>
      <p>Status: <span style="color: green;">Online</span></p>
    </body>
  </html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", index_html);
}


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // if (WiFi.waitForConnectResult() != WL_CONNECTED) {
  //   Serial.println("WiFi Failed!");
  //   return;
  // }
  
  Serial.println("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // put your main code here, to run repeatedly:

  server.handleClient();

}
