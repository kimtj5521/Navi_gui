#ifndef ROS_PUBLISH_H
#define ROS_PUBLISH_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <ros/master.h>

#include <std_msgs/Float64MultiArray.h>

#include <iostream>
#include <sstream>

using namespace std;

class ros_publish
{
public:
    ros_publish();

    ros::Publisher pub_gps_init;

    void publish_topic();
};

#endif // ROS_PUBLISH_H
