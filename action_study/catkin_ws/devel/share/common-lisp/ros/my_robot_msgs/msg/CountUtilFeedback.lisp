; Auto-generated. Do not edit!


(cl:in-package my_robot_msgs-msg)


;//! \htmlinclude CountUtilFeedback.msg.html

(cl:defclass <CountUtilFeedback> (roslisp-msg-protocol:ros-message)
  ((percentage
    :reader percentage
    :initarg :percentage
    :type cl:float
    :initform 0.0))
)

(cl:defclass CountUtilFeedback (<CountUtilFeedback>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CountUtilFeedback>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CountUtilFeedback)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_robot_msgs-msg:<CountUtilFeedback> is deprecated: use my_robot_msgs-msg:CountUtilFeedback instead.")))

(cl:ensure-generic-function 'percentage-val :lambda-list '(m))
(cl:defmethod percentage-val ((m <CountUtilFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_robot_msgs-msg:percentage-val is deprecated.  Use my_robot_msgs-msg:percentage instead.")
  (percentage m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CountUtilFeedback>) ostream)
  "Serializes a message object of type '<CountUtilFeedback>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'percentage))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CountUtilFeedback>) istream)
  "Deserializes a message object of type '<CountUtilFeedback>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'percentage) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CountUtilFeedback>)))
  "Returns string type for a message object of type '<CountUtilFeedback>"
  "my_robot_msgs/CountUtilFeedback")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CountUtilFeedback)))
  "Returns string type for a message object of type 'CountUtilFeedback"
  "my_robot_msgs/CountUtilFeedback")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CountUtilFeedback>)))
  "Returns md5sum for a message object of type '<CountUtilFeedback>"
  "46302a97c06fe5a4416c427fe6ee8804")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CountUtilFeedback)))
  "Returns md5sum for a message object of type 'CountUtilFeedback"
  "46302a97c06fe5a4416c427fe6ee8804")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CountUtilFeedback>)))
  "Returns full string definition for message of type '<CountUtilFeedback>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#feedback~%float64 percentage~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CountUtilFeedback)))
  "Returns full string definition for message of type 'CountUtilFeedback"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#feedback~%float64 percentage~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CountUtilFeedback>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CountUtilFeedback>))
  "Converts a ROS message object to a list"
  (cl:list 'CountUtilFeedback
    (cl:cons ':percentage (percentage msg))
))
