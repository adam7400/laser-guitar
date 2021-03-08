cmake_minimum_required(VERSION 3.19)

project(SPACE_HARP)

add_executable(${PROJECT_NAME} main.cpp)


target_link_directories(SPACE_HARP PRIVATE /usr/include)
target_link_libraries(SPACE_HARP wiringPi)

find_package (Threads)
target_link_libraries (SPACE_HARP ${CMAKE_THREAD_LIBS_INIT})
