#include "ros_publish.h"

ros_publish::ros_publish()
{

}

void ros_publish::publish_topic()
{
    ros::NodeHandle nh2;

    pub_gps_init = nh2.advertise<std_msgs::String>("init", 100);

    std_msgs::String pub_msg;

    pub_msg.data.clear();

    stringstream ss;
    ss << "hello";
    pub_msg.data = ss.str();

    pub_gps_init.publish(pub_msg);
}
