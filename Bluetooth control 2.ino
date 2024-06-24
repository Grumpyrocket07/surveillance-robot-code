#include "MiniHashHumanoid.h"
#include <BluetoothSerial.h>

MiniHashHumanoid minihash;
BluetoothSerial SerialBT;
bool stopFlag = false;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT_Control");
  
  Serial.println("GPIO test!");
  delay(5000);
  minihash.init_hash();
  minihash.initial_position();
  delay(2000);
}

void loop() {
  if (SerialBT.available()) {
    String input = SerialBT.readStringUntil('\n');
    input.trim();

    Serial.print("Received: ");
    Serial.println(input);

    if (input.equalsIgnoreCase("end")) {
      stopFlag = true;
      Serial.println("Stopping all actions...");
    } else if (input.equalsIgnoreCase("say hi")) {
      performSayHi();
    } else if (input.equalsIgnoreCase("move forward")) {
      performMoveForward();
    } else if (input.equalsIgnoreCase("move backward")) {
      performMoveBackward();
    }
  }
}

void performSayHi() {
  Serial.println("Performing say hi...");
  minihash.say_hi(2);
  delay(1000);
  minihash.hands_up();
  delay(1000);
  minihash.hands_down();
  delay(1000);
  minihash.hand_wave(3);
  delay(1000);
}

void performMoveForward() {
  Serial.println("Performing move forward...");
  minihash.move_forward(5, 1000); // Example: move forward for 5 seconds
}

void performMoveBackward() {
  Serial.println("Performing move backward...");
  minihash.move_backward(5, 1000); // Example: move backward for 5 seconds
}
