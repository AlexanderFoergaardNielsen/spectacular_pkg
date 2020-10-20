#include <ros/ros.h>
#include <geometry_msgs/Twist.h>



int main(int argc, char *argv[])
{
    double i = 0;
    ros::init(argc, argv, "roundround");
    
    
    
    ros::NodeHandle n;
    ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);

    geometry_msgs::Twist cmd_vel_message;
    
    
   
    

    ros::Rate loop_rate(10);
    
    while (ros::ok())
    {
        bool forward = true;
        
        if (i >= 10 || forward == true)
        {
            i = i - 0.1;
            forward == false;
        }
        else if (i <= 0 || forward == false)
        {
            i = i + 0.1;
            forward == true;
        }
        
        cmd_vel_message.linear.x = i;
        
        if (forward == true)
        {
            cmd_vel_message.angular.z = 10;
        }
        else
        {
            cmd_vel_message.angular.z = -10;
        }

        
        

        cmd_vel_pub.publish(cmd_vel_message);
        loop_rate.sleep();
    }

    
}
