#include "USBHost_t36.h"
// try this code after removing all usb lines

//initialising usbs (connections) wagera
USBHost myusb;
USBHub hub1(myusb);
USBHIDParser hid1(myusb);
JoystickController joystick1(myusb);
BluetoothController bluet(myusb, true, "0000"); //imp for pairing (first time specially)
//total drivers
USBDriver *drivers[] = {&hub1, &joystick1, &hid1};
#define CNT_DEVICES (sizeof(drivers)/sizeof(drivers[0]))

void setup() {
  Serial.begin(2000000);
  while (!Serial);
  Serial.println("\nPS4 Controller Joystick Test");
  myusb.begin();
}

void loop() {
  myusb.Task();

  if (joystick1.available()) {

    int lX = joystick1.getAxis(0);
    int lY = joystick1.getAxis(1);
    int rX = joystick1.getAxis(2);
    int rY = joystick1.getAxis(5); //change to 3 if not working

    int leftX = map(lX, 0, 255, -127, 127);
    int leftY = map(lY, 0, 255, 127, -127);
    int rightX = map(rX, 0, 255, -127, 127);
    int rightY = map(rY, 0, 255, 127, -127);


    Serial.print("Left Stick  X: ");
    Serial.print(leftX);
    Serial.print(" Y: ");
    Serial.print(leftY);
    Serial.print("  Right Stick  X: ");
    Serial.print(rightX);
    Serial.print(" Y: ");
    Serial.println(rightY);

    joystick1.joystickDataClear();
    
    delay(100);
  }
}
