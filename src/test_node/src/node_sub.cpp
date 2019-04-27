#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr &msg)
{
	ROS_INFO("Hello node_pub! I am node_sub. I heard:[%s]",msg->data.c_str());
}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"node_sub_instance");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("message",1000,chatterCallback);
	ros::spin();

	return 0;
}
