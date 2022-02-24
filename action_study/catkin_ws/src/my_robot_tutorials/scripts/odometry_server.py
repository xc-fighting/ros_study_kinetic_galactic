#!/usr/bin/env python
import rospy
import actionlib

from my_robot_msgs.msg import OdometryAction
from my_robot_msgs.msg import OdometryGoal
from my_robot_msgs.msg import OdometryResult
from my_robot_msgs.msg import OdometryFeedback


class OdometryServer:

    def __init__(self):

        self._as = actionlib.SimpleActionServer("/odometry", 
        OdometryAction, 
        execute_cb=self.on_goal, 
        auto_start=False)

        self._as.start()
        self.position = 50

    def on_goal(self, goal):
        rospy.loginfo("receive a goal {}".format(goal))
        destination = goal.position
        velocity = goal.velocity
        rate = rospy.Rate(1.0)

        success = False
        preempt = False

        while not rospy.is_shutdown():

            if self._as.is_preempt_requested():
                if destination == self.position:
                    success = True
                    break
                else:
                    preempt = True
                    break

            diff = destination - self.position
            if diff == 0:
                success = True
                break
            elif diff > 0:
                if diff >= velocity:
                    self.position += velocity
                else:
                    self.position += diff
            else:
                dist = abs(diff)
                if dist >= velocity:
                    self.position -= velocity
                else:
                    self.position -= diff

            feedback = OdometryFeedback()
            feedback.position = cur_pos
            self._as.publish_feedback(feedback)
            rate.sleep()

        result = OdometryResult()
        result.position = self.position
        result.message = "reach the goal"
        if preempt == True:
            rospy.loginfo("preempt the goal")
            self._as.set_preempted(result)
        if success == True:
            rospy.loginfo("reach the position")
            self._as.set_succeeded(result)
        else:
            rospy.loginfo("abort the moving")
            self._as.set_aborted(result)


if __name__ == "__main__":
    
    rospy.init_node("odometry_server")
    rospy.loginfo("start the server")
    server = OdometryServer()

    rospy.spin()