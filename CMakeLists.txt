cmake_minimum_required(VERSION 3.13)
project(clion_opencv_tutorials1)

set(CMAKE_CXX_STANDARD 11)

set(OpenCV_DIR "C:\\opencv-build\\opencv-3.4.7-qt\\install")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(clion_opencv_app main.cpp)
add_executable(example_15-01 example_15-01.cpp)
add_executable(example_15-02 example_15-02.cpp)
add_executable(example_15-03 example_15-03.cpp)
add_executable(example_15-04 example_15-04.cpp)


target_link_libraries(clion_opencv_app ${OpenCV_LIBS})
target_link_libraries(example_15-01 ${OpenCV_LIBS})
target_link_libraries(example_15-02 ${OpenCV_LIBS})
target_link_libraries(example_15-03 ${OpenCV_LIBS})
target_link_libraries(example_15-04 ${OpenCV_LIBS})