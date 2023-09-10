cmake_minimum_required(VERSION 2.8.3)

project(Robot_URDF)

find_package(catkin REQUIRED COMPONENTS
						roscpp
						geometry_msgs
						sensor_msgs
)

catkin_package()

find_package(roslaunch
#geometry_msgs
#sensor_msgs
)



# catkin_package(
# CATKIN_DEPENDS roscpp geometry_msgs sensor_msgs
# )


						include_directories(     
						${catkin_INCLUDE_DIRS}    
						)


						add_executable(control_robot src/control_robot.cpp)


						target_link_libraries(control_robot
				     	${catkin_LIBRARIES}
						)

						add_dependencies(control_robot ${control_robot_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


# foreach(dir config launch meshes urdf)
# 	install(DIRECTORY ${dir}/
# 		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
# endforeach(dir)
