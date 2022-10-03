
#include "ros/ros.h"
#include <std_msgs/UInt16.h>
#include "math.h"
#include "ros/time.h"
#include "sensor_msgs/JointState.h"


double convert(std_msgs::UInt16 x){
    return x;
}


int main(int argv, char **argc) {

    // Initialize node
    ros::init(argv, argc, "CPP_Joint_State_Controller");
    // Node handler
    ros::NodeHandle nodeHandler;
    ros::NodeHandle nh;
    // Publisher
    ros::Publisher publisherObject = nodeHandler.advertise<sensor_msgs::JointState>("joint_states", 10);
    ros::Publisher pub = nh.advertise<std_msgs::UInt16>("servo_pos",1000);

    // Rate controller 5 Hz
    ros::Rate rateController = ros::Rate(20);

    std_msgs::UInt16 var;
    // Variables
    double angle = 0.0;              // Angle
    bool increment = true;
    sensor_msgs::JointState msg;    // Message to be published
    msg.header.frame_id = "";           // Empty frame ID
    msg.name.resize(1);                 // A 1 unit size vector
    msg.position.resize(1);             // A 1 unit size vector
    msg.name[0] = "joint_0";

  


    // Main iterative code
    while(ros::ok()) {

        
        // Update header
        msg.header.stamp = ros::Time::now();    // Assign time
        msg.position[0] = angle;
        publisherObject.publish(msg);
        msg.header.seq ++; 

        double g =convert(var);
        angle =g*(M_PI/180); 
        
                            // Next sequence
        int x=0;
             for (x=0; x<=180; x+=1){
                 

                 
                 pub.publish(var);

    
 
                  ros::Duration(0.02).sleep();

                  }
             for (x=180; x>=0; x-=1){

                
                   pub.publish(var);
 
                
                  ros::Duration(0.02).sleep();

               }
             

        // Control rate
        rateController.sleep();
    }
    // End code
    return 0;
}
