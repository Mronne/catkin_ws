//nodelet_example_class.h
 
#ifndef NODELET_EXAMPLE_CLASS_SRC_NODELET_EXAMPLE_CLASS_H_
#define NODELET_EXAMPLE_CLASS_SRC_NODELET_EXAMPLE_CLASS_H_
#include <nodelet/nodelet.h>
#include <ros/ros.h>
#include <std_msgs/Float64.h>


namespace nodelet_example_ns
{
class NodeletExampleClass : public nodelet::Nodelet
{
public:
    NodeletExampleClass();
    ~NodeletExampleClass();

    virtual void onInit();
private:
    float value_;

    ros::Subscriber plus_subscriber_,minus_subscriber_;
    ros::Publisher  result_plus_pub_,result_minus_pub_;

    void plus_Callback(const std_msgs::Float64::ConstPtr& input);

    void minus_Callback(const std_msgs::Float64::ConstPtr& input);
};
} // namespace nodelet_example_ns

#endif /* NODELET_EXAMPLE_CLASS_SRC_NODELET_EXAMPLE_CLASS_H_ */
