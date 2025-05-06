
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Replace with your WiFi network credentials
const char* ssid = "A55";
const char* password = "12345678";

// ThingSpeak API key and server
String apiKey = "your_thingsspeak_api";
const char* server = "http://api.thingspeak.com/update";

WiFiClient client;  // <-- Add a WiFiClient globally

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Generate dummy data
    float temperature = random(200, 350) / 10.0; // 20.0°C to 35.0°C
    float humidity = random(400, 800) / 10.0;    // 40.0% to 80.0%	

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C\tHumidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Create URL
    String url = String(server) + "?api_key=" + apiKey + "&field1=" + String(temperature) + "&field2=" + String(humidity);

    http.begin(client, url); // <-- Pass client + url
    int httpResponseCode = http.GET(); // Send the GET request

    if (httpResponseCode > 0) {
      Serial.print("Data sent successfully, response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error sending data. HTTP response code: ");
      Serial.println(httpResponseCode);
    }

    http.end(); // Free resources
  } else {
    Serial.println("WiFi Disconnected");
  }

  delay(15000); // ThingSpeak allows updates every 15 seconds
}
