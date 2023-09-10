// #include "geometry_msgs/Twist.h"
// #include "ros/ros.h"
// #include "sensor_msgs/LaserScan.h"
// class MoveRobot {
//     private:
//     ros::Publisher pub;
//     ros::NodeHandle nhMove;
//     public:
//     MoveRobot() {
//     pub = nhMove.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
//     };
//     void laser_callback(const sensor_msgs::LaserScanConstPtr &msg) {
//     ROS_INFO("%f", msg->ranges[360]);
//     ros::Rate rate(1);
//     geometry_msgs::Twist move;
//     if (msg->ranges[360] > 1) {
//     move.linear.x = 0.1;
//     move.angular.z = 0.0;
//     pub.publish(move);
//     }
//     if (msg->ranges[360] < 1) {
//     move.linear.x = 0.0;
//     move.angular.z = 0.2;
//     pub.publish(move);
//     }
//     if (msg->ranges[0] < 1) {
//     move.linear.x = 0.0;
//     move.angular.z = 0.2;
//     pub.publish(move);
//     }
//     if (msg->ranges[719] < 1) {
//     move.linear.x = 0.0;
//     move.angular.z = -0.2;
//     pub.publish(move);
//     }
//     rate.sleep();
//     }
// };

// int main(int argc, char **argv) {
// ros::init(argc, argv, "topics_quiz_node");
// ros::NodeHandle nh;
// ros::Subscriber sub;
// MoveRobot moveRobot;
// sub = nh.subscribe("/kobuki/laser/scan", 1, &MoveRobot::laser_callback,
// &moveRobot);
// ros::spin();
// return 0;
// }