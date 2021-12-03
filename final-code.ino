#include <QubitroMqttClient.h>
#include <ESP8266WiFi.h>
// WiFi Client
#define SensorPin A0
WiFiClient wifiClient;
// Qubitro Client
QubitroMqttClient mqttClient(wifiClient);
// Device Parameters
char deviceID[] = "ADD_DEVICE_UNIQUE_ID";
char deviceToken[] = "ADD_DEVICE_UNIQUE_TOKEN";
// WiFi Parameters
const char* ssid = "ADD_WIFI_SSID";
const char* password = "ADD_WIFI_PASSWORD";
void setup() {
  // Initialize the serial port
  serial_init();
  // Initialize wireless connectivity
  wifi_init();
  // Initialize Qubitro
  qubitro_init();
}
void loop() {
  float sensorValue = analogRead(SensorPin);
  Serial.println(sensorValue);
  String payload = "{\"Sensor \":" + String(sensorValue)+ "}";
  mqttClient.poll();
  mqttClient.beginMessage(deviceID);
  mqttClient.print(payload);
  mqttClient.endMessage();
  // Delay
  delay(30 * 1000);
}
// Initialization code
void serial_init() {
  // Initiate serial port connection
  Serial.begin(115200);
  // Delay for stabilization
  delay(200);
}
void wifi_init() {
  // Set WiFi mode
  WiFi.mode(WIFI_STA);
  // Disconnect WiFi
  WiFi.disconnect();
  delay(100);
  // Initiate WiFi connection
  WiFi.begin(ssid, password);
  // Print connectivity status to the terminal
  Serial.print("Connecting to WiFi...");
  while(true)
  {
    delay(1000);
    Serial.print(".");
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("");
      Serial.println("WiFi Connected.");
      Serial.print("Local IP: ");
      Serial.println(WiFi.localIP());
      Serial.print("RSSI: ");
      Serial.println(WiFi.RSSI());
      break;
    }
  }
}
void qubitro_init() {
  char host[] = "broker.qubitro.com";
  int port = 1883;
  mqttClient.setId(deviceID);
  mqttClient.setDeviceIdToken(deviceID, deviceToken);
  Serial.println("Connecting to Qubitro...");
  if (!mqttClient.connect(host, port))
  {
    Serial.print("Connection failed. Error code: ");
    Serial.println(mqttClient.connectError());
    Serial.println("Visit docs.qubitro.com or create a new issue on github.com/qubitro");
  }
  Serial.println("Connected to Qubitro.");
  mqttClient.subscribe(deviceID);
}
