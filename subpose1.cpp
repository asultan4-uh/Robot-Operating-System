// This program subscribes to turtle1/pose and shows its
// messages on the screen.
#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <iomanip> // for std::setprecision and std::fixed
#include <math.h>
//#include <conio.h>

float vara = 8;
float varb = 9;
float a;
float b;



// A callback function.  Executed each time a new pose
// message arrives.
void poseMessageReceived(const turtlesim::Pose& msg) {
  ROS_INFO_STREAM(std::setprecision(2) << std::fixed
    << "position=(" <<  msg.x << "," << msg.y << ")"
    << " direction=" << msg.theta);
    a = msg.x;
    b = msg.y;
    if(sqrt((pow((a-vara),2.0))+pow((b-varb),2.0)) < 4.5)
    ROS_DEBUG_STREAM( " The turtle is nearing the bomb by 4.5! Debug " ) ;
    if(sqrt((pow((a-vara),2.0))+pow((b-varb),2.0)) < 3.5)
    ROS_INFO_STREAM( " The turtle is nearing the bomb by 3.5! Information" ) ;
    if(sqrt((pow((a-vara),2.0))+pow((b-varb),2.0)) < 2.5)
    ROS_WARN_STREAM( " The turtle is nearing the bomb by 2.5! Warning " ) ;
    if(sqrt((pow((a-vara),2.0))+pow((b-varb),2.0)) < 1.5)
    ROS_ERROR_STREAM( " The turtle is nearing the bomb by 1.5! Error " ) ;
    if(sqrt((pow((a-vara),2.0))+pow((b-varb),2.0)) < 0.5)
    ROS_FATAL_STREAM( " The turtle is nearing the bomb by 0.5! Fatal " ) ;

}

int main(int argc, char **argv) {
  // Initialize the ROS system and become a node.
  ros::init(argc, argv, "subscribe_to_pose");
  ros::NodeHandle nh;
  // Create a subscriber object.
  ros::Subscriber sub = nh.subscribe("turtle1/pose", 1000,
    &poseMessageReceived);

  // Let ROS take over.
  ros::spin();
}
