#include "MiniHashHumanoid.h"

MiniHashHumanoid minihash;
bool stopFlag = false;

void setup() {
  Serial.begin(115200);
  Serial.println("GPIO test!");
  delay(5000);
  minihash.init_hash();
  minihash.initial_position();
  delay(2000);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim(); // Remove any leading/trailing whitespace
    
    if (input.equalsIgnoreCase("end")) {
      stopFlag = true;
      Serial.println("Stopping all actions...");
    } else if (input.equalsIgnoreCase("say hi")) {
      performSayHi();
    } else if (input.equalsIgnoreCase("move forward")) {
      performMoveForward();
    } else if (input.equalsIgnoreCase("move backward")) {
      performMoveBackward();
    } // Add more commands as needed
  }
}

void performSayHi() {
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
  minihash.move_forward(5, 1000); // Example: move forward for 5 seconds
}

void performMoveBackward() {
  minihash.move_backward(5, 1000); // Example: move backward for 5 seconds
}
