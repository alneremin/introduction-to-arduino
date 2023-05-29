#include <ros.h>
#include <std_msgs/UInt8.h>

ros::NodeHandle  nh;

const int redLedPin = 9;
const int greenLedPin = 10;
const int yellowLedPin = 11;

int redLedState = 0, greenLedState = 0, yellowLedState = 0;

void commandCollback(std_msgs::UInt8 value) {
    // Serial.println(value.data);
    char symbol = value.data;
    switch (symbol)
    {
        case 'R': case 'r':
            redLedState = !redLedState;
            break;
        case 'G': case 'g':
            greenLedState = !greenLedState;
            break;
        case 'Y': case 'y':
            yellowLedState = !yellowLedState;
            break;
        default:
            break;
    }
}

ros::Subscriber<std_msgs::UInt8> command_sub("/command", commandCollback);


void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);

  nh.initNode();
  nh.subscribe(command_sub);
  
//   Serial.begin(57600);
}

void loop() {
  nh.spinOnce();
  digitalWrite(redLedPin, redLedState);
  digitalWrite(greenLedPin, greenLedState);
  digitalWrite(yellowLedPin, yellowLedState);
}
