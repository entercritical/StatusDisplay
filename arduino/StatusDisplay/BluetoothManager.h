#ifndef BluetoothManger_h
#define BluetoothManger_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class BluetoothManager {
  private:
    SoftwareSerial* bluetooth; 
  public:
    BluetoothManager(int rx, int tx);
    void begin(long speed);
    bool available();
    int read();
};

#endif
