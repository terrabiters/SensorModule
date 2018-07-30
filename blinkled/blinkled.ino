#include <ros.h>
#include <std_msgs/Empty.h>


// instantiate handler note which allows program to create publishers
// and subscibers and handles serial port communication
ros::NodeHandle nh;


// callback function for the subsriber. Call back function must take constant
// reference of a message as its argument. Type of message is std_msgs::Empy
// and the message name will be toggle_msg
void messageCb( const std_msgs::Empty& toggle_msg) {;
  digitalWrite(13, HIGH-digitalRead(13));
}



// insantiate subsciber. template must be baced on the message.
// two arguments are topic being subscribed to and callback function
ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );

void setup() {
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);

}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
  delay(1);

}

//TO RUN
//roscore
//new terminal: rosrun rosserial_python serial_node.py /dev/ttyUSB0
//USE CORRECT Serial port in above line
//new terminal
//rostopic pub toggle_led std_msgs/Empty --once
