#include "ros/ros.h"
#include "sensor_msgs/JointState.h"


int main(int argc, char ** argv)
{
	ros::init(argc,argv, "js_publisher");
	ros::NodeHandle n;
    ros::Publisher pub_joint = n.advertise<sensor_msgs::JointState>("joint_states",1000);
	ros::Rate r(0.05);

    sensor_msgs::JointState joint_msg;

    // joint_msg.header.stamp = ros::Time::now();
    // joint_msg.name.resize(1);
    // joint_msg.position.resize(1);

    // joint_msg.velocity[0] = 0;
    // joint_msg.effort[0] = 0;

    while(ros::ok()){
	int x=0;
  


    // for (x=0; x<=180; x+=1){


      
    //     joint_msg.name[0] = "joint_0";
    //     joint_msg.position[0] = x;
    //     pub_joint.publish(joint_msg);
    //     // ros::Duration(0.02).sleep();

    // }
    //     for (x=180; x>=0; x-=1){

    //     joint_msg.name[0] = "joint_0";
    //     joint_msg.position[0] = x;
    //     pub_joint.publish(joint_msg);
    //     // ros::Duration(0.02).sleep();

    // }
 
    
    ros::spinOnce();

	}
	return 0;
}

