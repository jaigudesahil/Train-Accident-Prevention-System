#define BLYNK_TEMPLATE_ID "TMPL3NyCAwvsl"
#define BLYNK_TEMPLATE_NAME "Train Accident Prevention"

#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
 
char auth[] = "O5Mj0ZtTvsM6WrKyM7qm8rwnHtwThqLT"; // Use your Blynk authentication token 
char ssid[] = "AAKASH";       // Your WiFi SSID 
char pass[] = "ad860986ds";   // Your WiFi password 
 
BlynkTimer timer; 
 
void setup() { 
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, pass); 
  timer.setInterval(1000L, sendDataToBlynk); // Adjust the interval as needed 
} 
 
void loop() { 
  Blynk.run(); 
  timer.run(); 
} 
 
void sendDataToBlynk() { 
  // Implement any data reception logic here, if needed 
  // For example, read data from Serial or any other source 
   
  // Update Blynk widgets based on received data 
  int distanceValue = 0; // Replace with actual value 
  String systemStatus = "System Inactive"; // Replace with actual status 
   
  Blynk.virtualWrite(V0, distanceValue); // Update distance widget (Value Display) 
  Blynk.virtualWrite(V1, distanceValue < 50 ? 255 : 0); // Update system active LED 
  Blynk.virtualWrite(V2, WiFi.status() == WL_CONNECTED ? 255 : 0); // Update Wi-Fi connection LED 
  Blynk.virtualWrite(V3, distanceValue < 50 ? 255 : 0); // Update buzzer activation LED 
  Blynk.virtualWrite(V4, systemStatus); // Update alarm status label 
  Blynk.virtualWrite(V5, systemStatus); // Update system status label 
}
