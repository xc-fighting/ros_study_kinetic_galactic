; Auto-generated. Do not edit!


(cl:in-package my_robot_msgs-msg)


;//! \htmlinclude CountUtilResult.msg.html

(cl:defclass <CountUtilResult> (roslisp-msg-protocol:ros-message)
  ((count
    :reader count
    :initarg :count
    :type cl:integer
    :initform 0))
)

(cl:defclass CountUtilResult (<CountUtilResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CountUtilResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CountUtilResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_robot_msgs-msg:<CountUtilResult> is deprecated: use my_robot_msgs-msg:CountUtilResult instead.")))

(cl:ensure-generic-function 'count-val :lambda-list '(m))
(cl:defmethod count-val ((m <CountUtilResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_robot_msgs-msg:count-val is deprecated.  Use my_robot_msgs-msg:count instead.")
  (count m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CountUtilResult>) ostream)
  "Serializes a message object of type '<CountUtilResult>"
  (cl:let* ((signed (cl:slot-value msg 'count)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CountUtilResult>) istream)
  "Deserializes a message object of type '<CountUtilResult>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'count) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CountUtilResult>)))
  "Returns string type for a message object of type '<CountUtilResult>"
  "my_robot_msgs/CountUtilResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CountUtilResult)))
  "Returns string type for a message object of type 'CountUtilResult"
  "my_robot_msgs/CountUtilResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CountUtilResult>)))
  "Returns md5sum for a message object of type '<CountUtilResult>"
  "8dbac33d2eb67bfeeedd516d65fec846")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CountUtilResult)))
  "Returns md5sum for a message object of type 'CountUtilResult"
  "8dbac33d2eb67bfeeedd516d65fec846")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CountUtilResult>)))
  "Returns full string definition for message of type '<CountUtilResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result~%int64 count~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CountUtilResult)))
  "Returns full string definition for message of type 'CountUtilResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result~%int64 count~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CountUtilResult>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CountUtilResult>))
  "Converts a ROS message object to a list"
  (cl:list 'CountUtilResult
    (cl:cons ':count (count msg))
))
