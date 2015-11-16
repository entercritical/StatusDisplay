#ifndef LedDisplay_h
#define LedDisplay_h

#include <Arduino.h>
#include "LedControl.h"

class LedDisplay {
  private:
    LedControl* led;
    int currentPosition;
  public:
    LedDisplay(int din, int clk, int cs, int num);
    void setup();
    void update();
};

#endif
