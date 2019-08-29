#include "ros_subscribe.h"

// ------------------------
// subscribe Navigation ros topioc
// ------------------------
ros_subscribe::ros_subscribe()
{
    ros_gps_x = 0.0;
    ros_gps_y = 0.0;
    ros_gps_heading = 0.0;
    ros_pos_x = 0.0;
    ros_pos_y = 0.0;
    ros_pos_heading = 0.0;

    ros_get_position = 0.0;
    ros_get_heading = 0.0;
    ros_POS_init = 1.0;
    ros_GPS_init = 0.0;
    ros_vehicle_speed = 0.0;
}

bool ros_subscribe::thread_start()
{
    if (!ros::master::check()){
        return false;//do not start without ros.
    }

    ros::start();
    ros::Time::init();
    ros::NodeHandle nh;

    listener_navi_topic = nh.subscribe("POS_T", 1, &ros_subscribe::subscribeCallback_ros_navi, this, ros::TransportHints().tcpNoDelay());
    start();

    return true;
}

void ros_subscribe::thread_stop()
{
    if(this->isRunning()){
        this->terminate();
    }
}

void ros_subscribe::subscribeCallback_ros_navi(const std_msgs::Float64MultiArray::ConstPtr& msg)
{
    ros_pos_x = msg->data[0];
    ros_pos_y = msg->data[1];
    ros_pos_heading = msg->data[2];
    ros_gps_x = msg->data[3];
    ros_gps_y = msg->data[4];
    ros_gps_heading = msg->data[5];

    ros_get_position = msg->data[6];
    ros_get_heading = msg->data[7];
    ros_POS_init = msg->data[8];
    ros_GPS_init = msg->data[9];
    ros_vehicle_speed = msg->data[10];
}

void ros_subscribe::run()
{
    ros::Rate loop_rate(100);
    while(ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }
}
