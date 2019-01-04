project( day1_part2 )
cmake_minimum_required( VERSION 2.8 )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a" )

add_executable( ${PROJECT_NAME} part2.cpp )

add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	${CMAKE_SOURCE_DIR}/../input.txt
	${CMAKE_CURRENT_BINARY_DIR}/input.txt)

