#include "exotica_rviz_plugins.h"
#include <pluginlib/class_list_macros.h>

namespace exotica_rviz_plugins {
exotica_rviz_plugins::exotica_rviz_plugins(QWidget* parent)
    : rviz::Panel(parent) {
  vbox_ = new QVBoxLayout();

  btnPlanPregrasp_ = new QPushButton(tr("Plan Pregrasp"));
  btnPlanGrasp_ = new QPushButton(tr("Plan Grasp"));
  btnPlanLift_ = new QPushButton(tr("Plan Lift"));
  btnSoftStop_ = new QPushButton(tr("Soft E-Stop"));

  btnPlanPregrasp_->setSizePolicy(QSizePolicy::Expanding,
                                  QSizePolicy::Expanding);
  btnPlanGrasp_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  btnPlanLift_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  btnSoftStop_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  vbox_->addWidget(btnPlanPregrasp_);
  vbox_->addWidget(btnPlanGrasp_);
  vbox_->addWidget(btnPlanLift_);
  vbox_->addWidget(btnSoftStop_);

  connect(btnPlanPregrasp_, SIGNAL(clicked()), this, SLOT(planPregrasp()));
  connect(btnPlanGrasp_, SIGNAL(clicked()), this, SLOT(planGrasp()));
  connect(btnPlanLift_, SIGNAL(clicked()), this, SLOT(planLift()));
  connect(btnSoftStop_, SIGNAL(clicked()), this, SLOT(softStop()));

  setLayout(vbox_);
}

void exotica_rviz_plugins::planGrasp() {
  std_srvs::Empty msg;
  srvPlanGrasp_.call(msg);
}

void exotica_rviz_plugins::planPregrasp() {
  std_srvs::Empty msg;
  srvPlanPregrasp_.call(msg);
}

void exotica_rviz_plugins::planLift() {
  std_srvs::Empty msg;
  srvPlanLift_.call(msg);
}

void exotica_rviz_plugins::softStop() {
  std_srvs::Empty msg;
  srvSoftStop_.call(msg);
}
}

PLUGINLIB_EXPORT_CLASS(exotica_rviz_plugins::exotica_rviz_plugins, rviz::Panel)
