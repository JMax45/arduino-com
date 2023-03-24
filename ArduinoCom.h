/*
  ArduinoCom.h - Library for facilitating categorization of messages over COM.

  Created by JMax, March 22, 2023.

  Released into the public domain.
*/

#ifndef ArduinoCom_h
#define ArduinoCom_h

#include "Arduino.h"

class Endpoint {
  public:
    char* route;
    void (*cb)(String payload);
};

class ArduinoCom
{
  public:
    void loop();
    Endpoint* routes = new Endpoint[0];
    void on(char* route, void (*cb)(String payload));
    void onDefault(void (*cb)(String body));
    void (*defaultHandler)(String body);
    int routes_size = 0;
    Stream *serial;
    ArduinoCom(Stream *serialPort);
};

#endif
