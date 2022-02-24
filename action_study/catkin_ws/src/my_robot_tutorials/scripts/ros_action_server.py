#!/usr/bin/env python
import rospy
import actionlib

from my_robot_msgs.msg import CountUtilGoal
from my_robot_msgs.msg import CountUtilResult
from my_robot_msgs.msg import CountUtilFeedback
from my_robot_msgs.msg import CountUtilAction

class RosActionServer:

    def __init__(self):
        self._as = actionlib.ActionServer("/count_util", CountUtilAction, self.on_goal, self.on_cancel, auto_start=False)
        self._as.start()
        rospy.loginfo("action server start")

    def process_goal(self, goal_handle):
        goal = goal_handle.get_goal()
        duration = goal.wait_duration
        max_number = goal.max_number
        if max_number > 100:
            goal_handle.set_rejected()
            return

        goal_handle.set_accepted()
        rate = rospy.Rate(1.0/duration)
        success = False
        preempted = False
        counter = 0

        while not rospy.is_shutdown():
            counter += 1
            rospy.loginfo(counter)
            if counter >= max_number:
                success = True
                break

            if counter >= 7:
                preempted = True
                break

            feedback = CountUtilFeedback()
            feedback.percentage = float(counter) / float(max_number)
            goal_handle.publish_feedback(feedback)
            rate.sleep()

        result = CountUtilResult()
        result.count = counter
        rospy.loginfo("send result to client")
        if preempted:
            rospy.loginfo("preempted")
            goal_handle.set_canceled(result)
        elif success:
            goal_handle.set_succeeded(result)
        else:
            goal_handle.set_aborted(result)



    def on_goal(self, goal_handle):
        rospy.loginfo("receive the new goal")
        rospy.loginfo("goal content: {}".format(goal_handle.get_goal()))
        self.process_goal(goal_handle)

    def on_cancel(self, goal_handle):
        rospy.loginfo("cancel the goal")
        rospy.loginfo(goal_handle)



if __name__ == "__main__":

    rospy.init_node("ros_action_server")
    server = RosActionServer()
    rospy.spin()