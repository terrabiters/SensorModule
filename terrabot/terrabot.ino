/* **************
 *  This is the main file
 *************** */

#include <ros.h>
#include <std_msgs/Empty.h>


// instantiate handler note which allows program to create publishers
// and subscibers and handles serial port communication
ros::NodeHandle teensy;

// callback function for the subsriber. Call back function must take constant
// reference of a message as its argument. Type of message is std_msgs::Empy
// and the message name will be toggle_msg
void blinkCB( const std_msgs::Empty& toggle_msg) {;
  digitalWrite(13, HIGH-digitalRead(13));
}


// insantiate subsciber. template must be baced on the message.
// two arguments are topic being subscribed to and callback function
ros::Subscriber<std_msgs::Empty> sub_led("toggle_led", &blinkCB);

void setup() {
  pinMode(13, OUTPUT);
  teensy.initNode();

  // subsribe to topic
  teensy.subscribe(sub_led);
}

void loop() {
  // put your main code here, to run repeatedly:
  teensy.spinOnce();
  delay(1);

}
