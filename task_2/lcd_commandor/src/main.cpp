#include <ros/ros.h>
#include <std_msgs/UInt8.h>
#include<iostream>
#include<stdio.h>

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "led_commandor");
    
    ros::NodeHandle node;
    system("stty raw");
    ros::Publisher pub = node.advertise<std_msgs::UInt8>("/command", 1);
    char letter;
    while (ros::ok()) {
        letter = getchar();
        system("clear");
        std::cout << "[W] - up [A] - left [S] - down [D] - right";
        std_msgs::UInt8 sym;
        sym.data = letter;
        if (letter == 'q') break;
        pub.publish(sym);
        ros::spinOnce();
    }
    system("stty cooked");
    return 0;
}
