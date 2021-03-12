cmake_minimum_required(VERSION 3.16.3)

project(ADC-test)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(ADC-test PRIVATE /usr/include)

target_link_libraries(ADC-test wiringPi)
