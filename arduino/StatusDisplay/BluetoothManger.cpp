#include "BluetoothManager.h"

BluetoothManager::BluetoothManager(int rx, int tx)
{
  this->bluetooth = new SoftwareSerial(rx, tx);
}

void BluetoothManager::begin(long speed)
{
  this->bluetooth->begin(speed);
}

bool BluetoothManager::available()
{
  return this->bluetooth->available();
}

int BluetoothManager::read()
{
  return this->bluetooth->read();
}
