cmake_minimum_required(VERSION 2.8.3)
project(exotica_rviz_plugins)

find_package(catkin REQUIRED)
find_package(Qt4 REQUIRED COMPONENTS QtCore QtGui)

catkin_package(
	DEPENDS rviz
    CATKIN_DEPENDS
    INCLUDE_DIRS # TODO include
    LIBRARIES # TODO
)

include(${QT_USE_FILE})
include_directories(include/)

qt4_wrap_cpp(QT_MOC include/exotica_rviz_plugins.h)
set(SOURCES src/exotica_rviz_plugins.cpp ${QT_MOC})
add_library(exotica_rviz_plugins ${SOURCES})
target_link_libraries(exotica_rviz_plugins ${QT_LIBRARIES} ${catkin_LIBRARIES} ${rviz_DEFAULT_PLUGIN_LIBRARIES})

install(FILES plugin_description.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
install(TARGETS exotica_rviz_plugins
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})
