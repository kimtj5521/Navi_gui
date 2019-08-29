#ifndef ROS_SUBSCRIBE_H
#define ROS_SUBSCRIBE_H

#include <QObject>
#include <QThread>
#include <QMutex>

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <ros/master.h>

#include <std_msgs/Float64MultiArray.h>

#include <iostream>

using namespace std;

class ros_subscribe: public QThread
{
    Q_OBJECT

public:
    ros_subscribe();

    ros::Subscriber listener_navi_topic;

    bool thread_start();
    void thread_stop();
    void run();
    void subscribeCallback_ros_navi(const std_msgs::Float64MultiArray::ConstPtr& msg);

    double ros_gps_x;
    double ros_gps_y;
    double ros_gps_heading;
    double ros_pos_x;
    double ros_pos_y;
    double ros_pos_heading;

    double ros_get_position;
    double ros_get_heading;
    double ros_POS_init;
    double ros_GPS_init;
    double ros_vehicle_speed;
};

#endif // ROS_SUBSCRIBE_H
