cmake_minimum_required(VERSION 3.16.3)

project(threadedADC)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PRIVATE /usr/include)

target_link_libraries(${PROJECT_NAME} wiringPi)

find_package (Threads)
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
