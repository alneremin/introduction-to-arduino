#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <rosbag/bag.h>
#include <iostream>
#include <iomanip>
#include <ctime>

rosbag::Bag bag;
const std::string tempTopic = "/temperature";
const std::string noiseTopic = "/noise";

void temperatureCollback(const std_msgs::Float32 &temperature);
void noiseCollback(const std_msgs::Float32 &noise);

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "data_saver");
    
    ros::NodeHandle node;

    ros::Time stamp = ros::Time::now();
    std::stringstream ss;
    ss << stamp.sec << "." << stamp.nsec;

    bag.open(ss.str() + "_sensor_data_saver.bag", rosbag::bagmode::Write);

    ros::Subscriber temperaturePub = node.subscribe(tempTopic, 10, temperatureCollback);
    ros::Subscriber noisePub = node.subscribe(noiseTopic, 10, noiseCollback);

    ros::spin();
    bag.close();
    return 0;
}

void temperatureCollback(const std_msgs::Float32 &temperature) {
    bag.write(tempTopic, ros::Time::now(), temperature);
}

void noiseCollback(const std_msgs::Float32 &noise) {
    bag.write(noiseTopic, ros::Time::now(), noise);
}
