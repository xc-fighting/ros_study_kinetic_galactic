#!/usr/bin/env python
import rospy
import actionlib

from my_robot_msgs.msg import OdometryAction
from my_robot_msgs.msg import OdometryGoal

class OdometryClient:

    def __init__(self):
        self.ac = actionlib.SimpleActionClient('/odometry', OdometryAction)
        self.ac.wait_for_server()
        rospy.loginfo("action client wait the server")


    def send_goal_for_result(self):

        goal = OdometryGoal(position = 100, velocity = 1.0)
        self.ac.send_goal(goal, done_cb = self.done_callback, feedback_cb = self.feedback_cb)
        rospy.loginfo("the goal has been sent")

    def done_callback(self, status, result):
        rospy.loginfo("reach the goal with status {}".format(status))
        rospy.loginfo("the result is: {}".format(result))

    def feedback_cb(self, feedback):
        rospy.loginfo("the current location {}".format(feedback))


if __name__ == "__main__":
    rospy.init("odometry_client")
    client = OdometrClient()
    client.send_goal_for_result()
    rospy.spin()