#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <Arduino.h>

class Button {

  private:
    byte pin;
    byte state = HIGH;
    byte lastReading;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 50;


  public:
    Button(byte pin);

    void init();
    void update();
    unsigned long pulseTime;
    byte getState();
    bool isPressed();
};

#endif
