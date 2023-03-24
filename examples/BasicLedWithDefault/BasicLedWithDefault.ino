#include <ArduinoCom.h>

ArduinoCom com(&Serial);

void setup() {
  Serial.begin(9600);
  com.on("led1", [](String payload) {
    Serial.print("led1 callback, Payload: ");
    Serial.println(payload);
  });
  com.on("led2", [](String payload) {
    Serial.print("led2 callback, Payload: ");
    Serial.println(payload);
  });
  com.onDefault([](String payload) {
    Serial.print("default callback, Payload: ");
    Serial.println(payload);
  });
}

void loop() {
  com.loop();
  delay(10);
}