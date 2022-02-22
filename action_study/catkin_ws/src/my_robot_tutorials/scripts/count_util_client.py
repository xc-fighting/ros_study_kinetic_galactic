import rospy
import actionlib

from my_robot_msgs.msg import CountUtilAction
from my_robot_msgs.msg import CountUtilGoal

class CountUtilClient:

    def __init__(self):
        self._ac = actionlib.SimpleActionClient('/count_util', CountUtilAction)
        self._ac.wait_for_server()
        rospy.loginfo("action client wait the server")

    def send_goal_and_get_result(self):

        goal = CountUtilGoal(max_number = 20, wait_duration = 1)
        self._ac.send_goal(goal, done_cb=self.done_callback, feedback_cb = self.feedback)
        rospy.loginfo("goal has been sent")
        #success = self._ac.wait_for_result(rospy.Duration(3.0))
        #if success == False:
        #    rospy.logwarn("TIMEOUT")
        #rospy.loginfo("get the result")
        #rospy.loginfo(self._ac.get_result())

    def done_callback(self, status, result):
        rospy.loginfo("the status is: {}".format(status))
        rospy.loginfo("the result is: {}".format(result))


    def feedback(self, feedback):
        rospy.loginfo("the feedback:{}".format(feedback))
    


if __name__ == "__main__":
    rospy.init_node("count_util_client")

    client = CountUtilClient()

    client.send_goal_and_get_result()

    rospy.spin()