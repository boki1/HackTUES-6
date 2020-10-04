//#include <SimpleEspNowConnection.h>
#include <WiFi.h>
#include <esp_now.h>


//#include <block.h>
//#include <cryptography.h>


uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

String success;

typedef struct struct_message {
  float temp;
  float hum;
  float pres;
} struct_message;


bool ns_chain::ns_node::DevRequest::Transmit(ns_chain::ns_block::Block tr_block, esp_now_peer_info_t *peerInfo) {
  uint8_t *msg_to_transmit = malloc(sizeof(ns_chain::ns_block::Block));

  return !(esp_now_send(broadcastAddress, (uint8_t *) &msg_to_transmit, sizeof(msg_to_transmit)));

}

void ns_chain::ns_node::DevRequest::Handle(const uint_8 *msg) {
  this->SetData(msg);

}

struct_message BME280Readings;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Fail" : "Delivery Success");
  if (status == 0) {
    success = "Delivery Success :)";
  }
  else {
    success = "Delivery Fail :(";
  }
}

// Callback when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&incomingReadings, incomingData, sizeof(incomingReadings));
  Serial.print("Bytes received: ");
  Serial.println(len);
  incomingTemp = incomingReadings.temp;
  incomingHum = incomingReadings.hum;
  incomingPres = incomingReadings.pres;
}

void setup() {
  // Init Serial Monitor
  Serial.begin(115200);

}

// Set device as a Wi-Fi Station
WiFi.mode(WIFI_STA);

// Init ESP-NOW
if (esp_now_init() != ESP_OK) {
  Serial.println("Error initializing ESP-NOW");
  return;
}

// Once ESPNow is successfully Init, we will register for Send CB to
// get the status of Trasnmitted packet
esp_now_register_send_cb(OnDataSent);

// Register peer
esp_now_peer_info_t peerInfo;
memcpy(peerInfo.peer_addr, broadcastAddress, 6);
peerInfo.channel = 0;
peerInfo.encrypt = false;

// Add peer
if (esp_now_add_peer(&peerInfo) != ESP_OK) {
  Serial.println("Failed to add peer");
  return;
}
// Register for a callback function that will be called when data is received
esp_now_register_recv_cb(OnDataRecv);


void loop() {
  getReadings();

  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &BME280Readings, sizeof(BME280Readings));

  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
}
void getReadings() {
  temperature = bme.readTemperature();
  humidity = bme.readHumidity();
  pressure = (bme.readPressure() / 100.0F);
}
