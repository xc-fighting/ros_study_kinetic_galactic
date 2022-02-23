#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>

#include <my_robot_msgs/CountUtilGoal.h>
#include <my_robot_msgs/CountUtilResult.h>
#include <my_robot_msgs/CountUtilFeedback.h>
#include <my_robot_msgs/CountUtilAction.h>

class CountUtilActionServer
{
protected:
    ros::NodeHandle nh;
    actionlib::SimpleActionServer<my_robot_msgs::CountUtilAction> as;
    int counter;

public:
    CountUtilActionServer() : as(nh, "/count_util",
                                 boost::bind(&CountUtilActionServer::onGoal, this, _1),
                                 false) {

        this->counter = 0;
        as.start();
        ROS_INFO("Action server has been started");
    }

    void onGoal(const my_robot_msgs::CountUtilGoalConstPtr &goal) {

        ROS_INFO("goal received");
        int max_number = goal->max_number;
        double wait_duration = goal->wait_duration;
        ROS_INFO("Max number and wait duration are %d, %lf", max_number, wait_duration);
        ros::Rate rate(1.0/wait_duration);
        bool success = false;
        bool cancel = false;

        while(ros::ok()) {

            counter++;
            if(as.isPreemptRequested()) {
                cancel = true;
                break;
            }

            if(counter > 9) {
                break;
            }

            if(counter >= max_number) {
                success = true;
                break;
            }

            ROS_INFO("The counter value is %d", counter);
            my_robot_msgs::CountUtilFeedback feedback;
            feedback.percentage = (double)(counter) / (double)(max_number);
            as.publishFeedback(feedback);
            rate.sleep();
        }


    }
};


int main(int argc, char** argv) {

    ros::init(argc, argv, "count_util_server");
    ROS_INFO("start the server now");
    CountUtilActionServer server;
    ros::spin();
}