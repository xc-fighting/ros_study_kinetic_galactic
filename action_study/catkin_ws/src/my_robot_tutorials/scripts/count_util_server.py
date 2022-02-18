#!/usr/bin/env python
import rospy
import actionlib

from my_robot_msgs.msg import CountUtilAction
from my_robot_msgs.msg import CountUtilGoal
from my_robot_msgs.msg import CountUtilResult

class CountUtilServer:

    def __init__(self):
        self._as = actionlib.SimpleActionServer('/count_util', CountUtilAction, execute_cb=self.on_goal, auto_start=False)
        self._as.start()
        self._counter = 0
        rospy.loginfo("action server is started")

    def on_goal(self, goal):
        rospy.loginfo("goal is received")
        rospy.loginfo(goal)
        max_number = goal.max_number
        wait_duration = goal.wait_duration

        self._counter = 0
        rate = rospy.Rate(1.0/wait_duration)

        while self._counter < max_number:
            self._counter += 1
            rate.sleep()

        result = CountUtilResult()
        result.count = self._counter
        self._as.set_succeeded(result)



if __name__ == "__main__":
    rospy.init_node("count_util_server")
    server = CountUtilServer()
    rospy.spin()
