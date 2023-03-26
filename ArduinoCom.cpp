/*
  ArduinoCom.cpp - Library for facilitating categorization of messages over COM.

  Created by JMax, March 22, 2023.

  Released into the public domain.
*/

#include "Arduino.h"
#include "ArduinoCom.h"

ArduinoCom::ArduinoCom(Stream *serialPort) {
  serial = serialPort;
}

void ArduinoCom::loop() {
  if(serial->available()) {
    String message = serial->readStringUntil('\n');
    message.trim();
    int index = 0;
    String endpoint;
    String payload;
    while(index <= message.length()) {
      if (message[index] == ';') {
        endpoint = message.substring(0, index);
        payload = message.substring(index + 1);
        break;
      } else {
        index += 1;
      }
    }

    index = 0;
    const char* endpointCharArray = endpoint.c_str();
    bool found = false;
    while(index < routes_size) {
      if(strcmp(routes[index].route, endpointCharArray) == 0) {
        routes[index].cb(payload);
        found = true;
        break;
      }
      index += 1;
    }
    if(!found && defaultHandler) defaultHandler(message);
  }
}

void ArduinoCom::on(char* route, void (*cb)(String payload)) {
  routes_size = routes_size + 1;

  size_t newSize = routes_size;
  Endpoint* newArr = new Endpoint[newSize];
  memcpy(newArr, routes, routes_size * sizeof(Endpoint));
  delete [] routes;
  routes = newArr;

  routes[routes_size-1].route = route;
  routes[routes_size-1].cb = cb;
}

void ArduinoCom::onDefault(void (*cb)(String body)) {
  defaultHandler = cb;
}