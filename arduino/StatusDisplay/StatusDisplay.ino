/*
  Status Display

 JY-MCU Bluetooth
 The circuit:
 * RX is digital pin 8 (connect to TX of other device)
 * TX is digital pin 9 (connect to RX of other device)


 */
#include <SoftwareSerial.h>

SoftwareSerial btSerial(8, 9); // RX, TX

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
  btSerial.begin(9600);
}

void loop() // run over and over
{
  if (btSerial.available()) {
    char c = btSerial.read();
    Serial.write(c);
    if (c == '0') {
      digitalWrite(13, LOW);  
    } else {
      digitalWrite(13, HIGH);
    }
  }
  //if (Serial.available())
  //  btSerial.write(Serial.read());
}

