#pragma once

#include <QtGui>

#include <ros/ros.h>
#include <rviz/panel.h>

#include <std_srvs/Empty.h>

namespace exotica_rviz_plugins {
class exotica_rviz_plugins : public rviz::Panel {
  Q_OBJECT

 public:
  exotica_rviz_plugins(QWidget* parent = 0);

 protected Q_SLOTS:
  void planGrasp();
  void planPregrasp();

 protected:
  QVBoxLayout* vbox_;

  QPushButton* btnPlanGrasp_;
  QPushButton* btnPlanPregrasp_;

 private:
  ros::NodeHandle nh;
  ros::ServiceClient srvPlanGrasp_ =
      nh.serviceClient<std_srvs::Empty>("/plan_grasp");
  ros::ServiceClient srvPlanPregrasp_ =
      nh.serviceClient<std_srvs::Empty>("/plan_pregrasp");
};
}
