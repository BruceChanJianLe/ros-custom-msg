#include <ros/ros.h>
#include <custom_msgs/CustomMsg.h>


int main(int argc, char ** argv)
{
    ros::init(argc, argv, "custom_package_node");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<custom_msgs::CustomMsg>("custom_topic", 1000);

    ros::Rate r(10);

    custom_msgs::CustomMsg msg;

    msg.data_1.assign(1, 1.0);
    msg.data_2.assign(2, 2.0);
    msg.data_3.assign(3, 3.0);

    while(ros::ok())
    {
        pub.publish(msg);

        ros::spinOnce();

        r.sleep();

    }

    return 0;

}