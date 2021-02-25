cmake_minimum_required(VERSION 3.19)

project(redLED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(redLED PRIVATE /usr/include)

target_link_libraries(redLED wiringPi)
