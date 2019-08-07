#include "ros/ros.h"
#include "nodelet/loader.h"

int main(int argc,char** argv)
{
    ROS_INFO("Starting node...");
    ros::init(argc, argv, "CoreNode");//初始化节点
    nodelet::V_string nargv;
    for(int i=1;i<argc;++i)
    {
       nargv.push_back(argv[i]);
    }
    nodelet::Loader nodelet;
    nodelet::M_string remap(ros::names::getRemappings());
    std::string nodelet_name = ros::this_node::getName();
    nodelet.load(nodelet_name, "nodelet_example/CoreNode", remap, nargv);
    ROS_INFO("CoreNode started...");
    ros::spin();
	return 0;
}
