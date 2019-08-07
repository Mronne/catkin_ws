//nodelet_example_class.cpp

#include "nodelet_example/nodelet_example_class.h"
#include <pluginlib/class_list_macros.h>

namespace nodelet_example_ns
{
NodeletExampleClass::NodeletExampleClass():value_(5)
{
  ROS_INFO("NodeletExampleClass Constructor");
}

NodeletExampleClass::~NodeletExampleClass()
{
  ROS_INFO("NodeletExampleClass Destructor");
}

void NodeletExampleClass::onInit()
{
    ros::NodeHandle & nh = getNodeHandle();
    
    NODELET_INFO("@@@onInit function!");
    plus_subscriber_ = nh.subscribe("plus/in",10,&NodeletExampleClass::plus_Callback,this);
    minus_subscriber_ = nh.subscribe("minus/in",10,&NodeletExampleClass::minus_Callback,this);
    
    result_minus_pub_ = nh.advertise<std_msgs::Float64>("minus/out",1);
    result_plus_pub_ =  nh.advertise<std_msgs::Float64>("plus/out",1);
}

void NodeletExampleClass::plus_Callback(const std_msgs::Float64::ConstPtr& input)
{
    std_msgs::Float64Ptr output(new std_msgs::Float64());
    output->data = input->data + value_;
    NODELET_INFO("@@@@function plus_Callback has been used!");
    result_plus_pub_.publish(output);
}

void NodeletExampleClass::minus_Callback(const std_msgs::Float64::ConstPtr& input)
{
    std_msgs::Float64Ptr output(new std_msgs::Float64());
    output->data = input->data - value_;
    NODELET_INFO("@@@@function minus_Callback has been used!");
    result_minus_pub_.publish(output);
}

} // namespace nodelet_example_ns

PLUGINLIB_EXPORT_CLASS(nodelet_example_ns::NodeletExampleClass, nodelet::Nodelet)
