/*
  Status Display

 JY-MCU Bluetooth
 The circuit:
 * RX is digital pin 8 (connect to TX of other device)
 * TX is digital pin 9 (connect to RX of other device)


 */
#include <SoftwareSerial.h>
#include "BluetoothManager.h"
#include "LedDisplay.h"

BluetoothManager bluetoothManager(8, 9);
LedDisplay ledDisplay(12, 10, 11, 1);

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.println("Start");

  pinMode(13, OUTPUT);
  // set the data rate for the SoftwareSerial port
  bluetoothManager.begin(9600);

  ledDisplay.setup();
}

void loop() // run over and over
{
  if (bluetoothManager.available()) {
    char c = bluetoothManager.read();
    Serial.write(c);
    if (c == '0') {
      digitalWrite(13, LOW);  
    } else {
      digitalWrite(13, HIGH);
    }
  }
  //if (Serial.available())
  //  btSerial.write(Serial.read());
  ledDisplay.update();
}

