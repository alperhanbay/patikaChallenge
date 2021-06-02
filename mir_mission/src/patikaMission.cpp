#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "simple_navigation_goals");
    MoveBaseClient ac("move_base", true);
   // MoveBaseClient ac2("move_base", true);

    while (!ac.waitForServer(ros::Duration(5.)))
    {
        ROS_INFO("Waiting for server .....");
    }
    move_base_msgs::MoveBaseGoal goal; 

    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp=ros::Time::now();

    goal.target_pose.pose.position.x = 2;
    goal.target_pose.pose.position.y = 8;
    goal.target_pose.pose.orientation.w = 0.640281897765;
    move_base_msgs::MoveBaseGoal goal2; // değişken ismi

    goal2.target_pose.header.frame_id = "map";
    goal2.target_pose.header.stamp=ros::Time::now();

    goal2.target_pose.pose.position.x = 10;
    goal2.target_pose.pose.position.y = 10;
    goal2.target_pose.pose.orientation.w = 0.640281897765;

    ROS_INFO("Sending Goal");
    ac.sendGoal(goal);
    ac.waitForResult();
    ac.sendGoal(goal2);
    ac.waitForResult();

    //std::cout<<ac.getstate()<<endl;
    if(ac.getState()==actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("The robot on the goal");
    else
        ROS_INFO("The robot cannot reach the goal");

    return 0;
}
