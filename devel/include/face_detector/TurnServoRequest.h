// Generated by gencpp from file face_detector/TurnServoRequest.msg
// DO NOT EDIT!


#ifndef FACE_DETECTOR_MESSAGE_TURNSERVOREQUEST_H
#define FACE_DETECTOR_MESSAGE_TURNSERVOREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace face_detector
{
template <class ContainerAllocator>
struct TurnServoRequest_
{
  typedef TurnServoRequest_<ContainerAllocator> Type;

  TurnServoRequest_()
    : order()  {
    }
  TurnServoRequest_(const ContainerAllocator& _alloc)
    : order(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _order_type;
  _order_type order;




  typedef boost::shared_ptr< ::face_detector::TurnServoRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::face_detector::TurnServoRequest_<ContainerAllocator> const> ConstPtr;

}; // struct TurnServoRequest_

typedef ::face_detector::TurnServoRequest_<std::allocator<void> > TurnServoRequest;

typedef boost::shared_ptr< ::face_detector::TurnServoRequest > TurnServoRequestPtr;
typedef boost::shared_ptr< ::face_detector::TurnServoRequest const> TurnServoRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::face_detector::TurnServoRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::face_detector::TurnServoRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace face_detector

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::face_detector::TurnServoRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::face_detector::TurnServoRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::face_detector::TurnServoRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::face_detector::TurnServoRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::face_detector::TurnServoRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::face_detector::TurnServoRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::face_detector::TurnServoRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9db207449ae86824d9e60bd906ef30e7";
  }

  static const char* value(const ::face_detector::TurnServoRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9db207449ae86824ULL;
  static const uint64_t static_value2 = 0xd9e60bd906ef30e7ULL;
};

template<class ContainerAllocator>
struct DataType< ::face_detector::TurnServoRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "face_detector/TurnServoRequest";
  }

  static const char* value(const ::face_detector::TurnServoRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::face_detector::TurnServoRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string order\n\
";
  }

  static const char* value(const ::face_detector::TurnServoRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::face_detector::TurnServoRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.order);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TurnServoRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::face_detector::TurnServoRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::face_detector::TurnServoRequest_<ContainerAllocator>& v)
  {
    s << indent << "order: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.order);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FACE_DETECTOR_MESSAGE_TURNSERVOREQUEST_H
