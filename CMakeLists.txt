cmake_minimum_required(VERSION 3.13)
project(clion_opencv_tutorials1)

set(CMAKE_CXX_STANDARD 11)

set(OpenCV_DIR "C:\\opencv-build\\opencv-3.4.7-qt\\install")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(clion_opencv_app main.cpp)
add_executable(example_13-01 example_13-01.cpp)
add_executable(example_13-02 example_13-02.cpp)
add_executable(example_13-03 example_13-03.cpp)
add_executable(Exercises_13_1-2-11 Exercises_13_1-2-11.cpp)
add_executable(Exercises_13_9 Exercises_13_9.cpp)


target_link_libraries(clion_opencv_app ${OpenCV_LIBS})
target_link_libraries(example_13-01 ${OpenCV_LIBS})
target_link_libraries(example_13-02 ${OpenCV_LIBS})
target_link_libraries(example_13-03 ${OpenCV_LIBS})
target_link_libraries(Exercises_13_1-2-11 ${OpenCV_LIBS})
target_link_libraries(Exercises_13_9 ${OpenCV_LIBS})