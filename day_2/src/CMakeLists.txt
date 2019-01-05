project( day2_part1 )
cmake_minimum_required( VERSION 3.4 )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -ggdb" )

add_executable( ${PROJECT_NAME} main.cpp )
set_target_properties( ${PROJECT_NAME} PROPERTIES ENABLE_EXPORTS 1 )

add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	${CMAKE_CURRENT_SOURCE_DIR}/input.txt
	${CMAKE_CURRENT_BINARY_DIR}/input.txt)

