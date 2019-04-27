#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
	ros::init(argc,argv,"node_pub_instance");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("message",1000);
	ros::Rate loop_rate(1);
	while(ros::ok()) {
		std_msgs::String msg;
		std::stringstream ss;
		ss << "Hello test1_b! I am test1_a.";
		msg.data = ss.str();
		ROS_INFO("%s",msg.data.c_str());
		chatter_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
