# ArduinoCom

Library for facilitating categorization of messages over COM.

## Installation

1. Download latest zip file from [releases](https://github.com/JMax45/arduino-com/releases) page.
2. Install the zip file via Sketch->#include->Add library from .ZIP file.

## Usage

```cpp
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
}

void loop() {
  com.loop();
  delay(10);
}
```

This example will print two different messages when receiving "led1;payload" or "led2;payload" over the passed Serial interface.

https://user-images.githubusercontent.com/36378436/227015891-77ea332c-cabd-431a-89f3-268cdf526e25.mp4
