cmake_minimum_required(VERSION 3.16.3)

project(singleString)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PRIVATE /usr/include)

target_link_libraries(${PROJECT_NAME} wiringPi)

target_link_directories(${PROJECT_NAME} PRIVATE /usr/include/linux/dvb)

target_link_libraries(${PROJECT_NAME} audio)

