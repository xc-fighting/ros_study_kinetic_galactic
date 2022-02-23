#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>

#include <my_robot_msgs/CountUtilAction.h>
#include <my_robot_msgs/CountUtilActionGoal.h>
#include <my_robot_msgs/CountUtilResult.h>
#include <my_robot_msgs/CountUtilFeedback.h>


class CountUtilClient {
protected:
  ros::NodeHandle nh;
  actionlib::SimpleActionClient<my_robot_msgs::CountUtilAction> ac;

public:
  CountUtilClient(): ac("/count_util", true) {

      ROS_INFO("wait for action server to start");
      //terrible idea to put it in constructor
      ac.waitForServer();
      ROS_INFO("server is now up");

  }

  void sendGoal() {
      my_robot_msgs::CountUtilGoal goal;
      goal.max_number = 12;
      goal.wait_duration = 1;
      ac.sendGoal(goal,
                 boost::bind(&CountUtilClient::doneCb, this, _1, _2),
                 boost::bind(&CountUtilClient::activeCb, this),
                 boost::bind(&CountUtilClient::feedbackCb, this, _1));
      ROS_INFO("Goal has been sent");

  }

  void doneCb(const actionlib::SimpleClientGoalState &state,
              const my_robot_msgs::CountUtilResultConstPtr &result) {
       
       ROS_INFO("Finish in state %s", state.toString().c_str());
       ROS_INFO("the count result is: %d", (int)result->count);

  }

  void activeCb() {
      ROS_INFO("Goal just active");
  }

  void feedbackCb(const my_robot_msgs::CountUtilFeedbackConstPtr &feedback) {
       ROS_INFO("Feedback received and percentage: %lf", feedback->percentage);
   
  }


};


int main(int argc, char **argv) {
    ros::init(argc, argv, "count_util_client");
    CountUtilClient client;
    client.sendGoal();
    ros::spin();
}