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
        goal = CountUtilGoal(max_number = 10, wait_duration = 0.5)
        self._ac.send_goal(goal)
        rospy.loginfo("goal has been sent")
        self._ac.wait_for_result()
        rospy.loginfo(self._ac.get_result())

if __name__ == "__main__":
    rospy.init_node("count_util_client")

    client = CountUtilClient()

    client.send_goal_and_get_result()