/*#include "ros/ros.h"
 #include "std_msgs/String.h" 
 #include "sensor_msgs/LaserScan.h" 
 #include "laser_geometry/laser_geometry.h" 
 #include "tf/message_filter.h"
#include "message_filters/subscriber.h" 
#include "sensor_msgs/PointCloud.h"
#include "sensor_msgs/Range.h"
                    #include <geometry_msgs/Twist.h>

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)

{  
    // for(int i=0;i<scan->ranges.size();i+360)

    // {   float range = scan->ranges[i];
       
// i = i-1;
// }

      float right = scan->ranges[0];
      float front = scan->ranges[360];
      float left = scan->ranges[719];


 order(right,front,left);


}

geometry_msgs::Twist* order(float right,float front,float left)
{

geometry_msgs::Twist *vel = new geometry_msgs::Twist ;

if (front<1&&left>1) //turn left 
{
   vel->linear.x=3;
    vel->angular.z=1.57079633;

}

else if (front<1&&left<1&&right>1) //turn right
{
        vel->linear.x=3;
        vel->angular.z= -1.57079633;
}

else if (front>1) //forward 
{
    vel->linear.x=3;

}

else if (front<1&&left<1&&right<1) // backward
{
         vel->linear.x= -3;
}
return vel ; 
}


int main(int argc, char **argv)

{
 unsigned int num_readings = 100;
        double laser_frequency = 40;
        double ranges[num_readings];
        double intensities[num_readings];
         //populate the LaserScan message
        ros::Time scan_time = ros::Time::now();
        sensor_msgs::LaserScan scan;
        scan.header.stamp = scan_time;
        scan.header.frame_id = "laser_frame";
        scan.angle_min = -1.57;
        scan.angle_max = 1.57;
        scan.angle_increment = 3.14 / num_readings;
        scan.time_increment = (1 / laser_frequency) / (num_readings);
        scan.range_min = 0.1;
        scan.range_max = 30.0;


ros::init(argc, argv, "move_robot_node");
        ros::NodeHandle nh;
ros::NodeHandle n;
ros::Subscriber subs = n.subscribe("scan", 10, scanCallback);
ros::spin();





        ros::Rate loop_rate(2); // Set a publish rate of 2 Hz 
        ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
      //  geometry_msgs::Twist vel;
        

        while (ros::ok()) // Create a loop that will go until someone stops the program execution
        {
                         pub.publish(vel); // Publish the message within the 'count' variable
        ros::spinOnce();
        loop_rate.sleep(); // Make sure the publish rate maintains at 2 Hz

        }
return 0;

}
*/