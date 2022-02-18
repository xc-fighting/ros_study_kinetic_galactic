
(cl:in-package :asdf)

(defsystem "my_robot_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :actionlib_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "CountUtilAction" :depends-on ("_package_CountUtilAction"))
    (:file "_package_CountUtilAction" :depends-on ("_package"))
    (:file "CountUtilActionFeedback" :depends-on ("_package_CountUtilActionFeedback"))
    (:file "_package_CountUtilActionFeedback" :depends-on ("_package"))
    (:file "CountUtilActionGoal" :depends-on ("_package_CountUtilActionGoal"))
    (:file "_package_CountUtilActionGoal" :depends-on ("_package"))
    (:file "CountUtilActionResult" :depends-on ("_package_CountUtilActionResult"))
    (:file "_package_CountUtilActionResult" :depends-on ("_package"))
    (:file "CountUtilFeedback" :depends-on ("_package_CountUtilFeedback"))
    (:file "_package_CountUtilFeedback" :depends-on ("_package"))
    (:file "CountUtilGoal" :depends-on ("_package_CountUtilGoal"))
    (:file "_package_CountUtilGoal" :depends-on ("_package"))
    (:file "CountUtilResult" :depends-on ("_package_CountUtilResult"))
    (:file "_package_CountUtilResult" :depends-on ("_package"))
  ))