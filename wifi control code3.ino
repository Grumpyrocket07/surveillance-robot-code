#include "MiniHashHumanoid.h"
#include <WiFi.h>

MiniHashHumanoid minihash;

// WiFi credentials
const char* ssid = "OPPOA96";
const char* password = "shreyank";

WiFiServer server(80); // Create a server on port 80

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to WiFi
  connectToWiFi();

  server.begin();

  minihash.init_hash();
  minihash.initial_position();
  delay(2000);

  Serial.println("Robot Control Server is running");
  Serial.print("Open this URL in your browser: http://");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  client.flush();

  // Extract the command from the request
  String input = getRequestParameter(request, "GET /?", " HTTP");

  Serial.print("Received command: ");
  Serial.println(input);

  if (input.equalsIgnoreCase("say_hi")) {
    performSayHi();
  } else if (input.equalsIgnoreCase("move_forward")) {
    performMoveForward();
  } else if (input.equalsIgnoreCase("move_backward")) {
    performMoveBackward();
  }

  // Send HTTP response
  sendHttpResponse(client);
  
  delay(1000);
}

void connectToWiFi() {
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

String getRequestParameter(String request, String startMarker, String endMarker) {
  int startIndex = request.indexOf(startMarker) + startMarker.length();
  int endIndex = request.indexOf(endMarker, startIndex);
  return request.substring(startIndex, endIndex);
}

void performSayHi() {
  minihash.say_hi(2);
  delay(1000);
  minihash.hands_up();
  delay(1000);
  minihash.hands_down();
  delay(1000);
  minihash.hand_wave(3);
  delay(1000);
}

void performMoveForward() {
  minihash.move_forward(5, 1000); // Example: move forward for 5 seconds
}

void performMoveBackward() {
  minihash.move_backward(5, 1000); // Example: move backward for 5 seconds
}

void sendHttpResponse(WiFiClient client) {
  // Send HTTP response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><title>ESP32 Robot Control</title></head>");
  client.println("<body>");
  client.println("<h1>ESP32 Robot Control</h1>");
  client.println("<p><a href='/?say_hi'>Say Hi</a></p>");
  client.println("<p><a href='/?move_forward'>Move Forward</a></p>");
  client.println("<p><a href='/?move_backward'>Move Backward</a></p>");
  client.println("</body>");
  client.println("</html>");
}
