#!/usr/bin/env python
import rospy
import actionlib

from my_robot_msgs.msg import CountUtilAction
from my_robot_msgs.msg import CountUtilGoal
from my_robot_msgs.msg import CountUtilResult
from my_robot_msgs.msg import CountUtilFeedback

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

        success = False
        cancel = False
        while not rospy.is_shutdown():
            self._counter += 1
            if self._as.is_preempt_requested():
                cancel = True
                break
            if self._counter > 9:
                break
            if self._counter >= max_number:
                success = True
                break
            rospy.loginfo("the counter value {}".format(self._counter))
            feedback = CountUtilFeedback()
            feedback.percentage = float(self._counter) / float(max_number)
            self._as.publish_feedback(feedback)
            rate.sleep()

        result = CountUtilResult()
        result.count = self._counter
        if cancel == True:
            rospy.loginfo("Cancel the goal")
            self._as.set_preempted(result)
        elif success == True:
            rospy.loginfo("Success")
            self._as.set_succeeded(result)
        else:
            rospy.loginfo("Abort")
            self._as.set_aborted(result)



if __name__ == "__main__":
    rospy.init_node("count_util_server")
    server = CountUtilServer()
    rospy.spin()
