// Generated by gencpp from file my_robot_msgs/CountUtilActionGoal.msg
// DO NOT EDIT!


#ifndef MY_ROBOT_MSGS_MESSAGE_COUNTUTILACTIONGOAL_H
#define MY_ROBOT_MSGS_MESSAGE_COUNTUTILACTIONGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <actionlib_msgs/GoalID.h>
#include <my_robot_msgs/CountUtilGoal.h>

namespace my_robot_msgs
{
template <class ContainerAllocator>
struct CountUtilActionGoal_
{
  typedef CountUtilActionGoal_<ContainerAllocator> Type;

  CountUtilActionGoal_()
    : header()
    , goal_id()
    , goal()  {
    }
  CountUtilActionGoal_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , goal_id(_alloc)
    , goal(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::actionlib_msgs::GoalID_<ContainerAllocator>  _goal_id_type;
  _goal_id_type goal_id;

   typedef  ::my_robot_msgs::CountUtilGoal_<ContainerAllocator>  _goal_type;
  _goal_type goal;





  typedef boost::shared_ptr< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> const> ConstPtr;

}; // struct CountUtilActionGoal_

typedef ::my_robot_msgs::CountUtilActionGoal_<std::allocator<void> > CountUtilActionGoal;

typedef boost::shared_ptr< ::my_robot_msgs::CountUtilActionGoal > CountUtilActionGoalPtr;
typedef boost::shared_ptr< ::my_robot_msgs::CountUtilActionGoal const> CountUtilActionGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace my_robot_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'my_robot_msgs': ['/home/offworld/action_study/catkin_ws/devel/share/my_robot_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "82e93ac26917dc555753523fc1c9fa4b";
  }

  static const char* value(const ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x82e93ac26917dc55ULL;
  static const uint64_t static_value2 = 0x5753523fc1c9fa4bULL;
};

template<class ContainerAllocator>
struct DataType< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "my_robot_msgs/CountUtilActionGoal";
  }

  static const char* value(const ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalID goal_id\n\
CountUtilGoal goal\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: actionlib_msgs/GoalID\n\
# The stamp should store the time at which this goal was requested.\n\
# It is used by an action server when it tries to preempt all\n\
# goals that were requested before a certain time\n\
time stamp\n\
\n\
# The id provides a way to associate feedback and\n\
# result message with specific goal requests. The id\n\
# specified must be unique.\n\
string id\n\
\n\
\n\
================================================================================\n\
MSG: my_robot_msgs/CountUtilGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#goal\n\
int64 max_number\n\
float64 wait_duration\n\
";
  }

  static const char* value(const ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.goal_id);
      stream.next(m.goal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CountUtilActionGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::my_robot_msgs::CountUtilActionGoal_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "goal_id: ";
    s << std::endl;
    Printer< ::actionlib_msgs::GoalID_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_id);
    s << indent << "goal: ";
    s << std::endl;
    Printer< ::my_robot_msgs::CountUtilGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.goal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MY_ROBOT_MSGS_MESSAGE_COUNTUTILACTIONGOAL_H