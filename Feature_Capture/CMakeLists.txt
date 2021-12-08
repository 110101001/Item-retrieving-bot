PROJECT(tracker)
cmake_minimum_required(VERSION 3.5)

SET(CMAKE_C_COMPILER "/usr/bin/gcc")
SET(CMAKE_CXX_COMPILER "/usr/bin/g++")
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -w -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("include/")
ADD_SUBDIRECTORY(src)
add_executable(Scanner main.cpp)
add_executable(Robot robot_main.cpp)
add_executable(load load.cpp)
link_directories(${OpenCV_LIBRARY_DIRS})
target_link_libraries(Scanner src)
target_link_libraries(Scanner ${OpenCV_LIBS})
target_link_libraries(load src)
target_link_libraries(load ${OpenCV_LIBS})

include("Findpigpio.cmake")
target_link_libraries(Robot src)
target_link_libraries(Robot ${OpenCV_LIBS})
target_link_libraries(Robot ${pigpio_LIBRARY} ${pigpiod_if_LIBRARY} ${pigpiod_if2_LIBRARY})

