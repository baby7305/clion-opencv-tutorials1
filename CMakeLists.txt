cmake_minimum_required(VERSION 3.13)
project(clion_opencv_tutorials1)

set(CMAKE_CXX_STANDARD 11)

set(OpenCV_DIR "C:\\opencv-build\\opencv-3.4.7-qt\\install")
find_package(OpenCV REQUIRED)
find_package(OpenGL)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(clion_opencv_app main.cpp)
add_executable(example_09-01 example_09-01.cpp)
add_executable(example_09-02 example_09-02.cpp)
add_executable(example_09-03 example_09-03.cpp)
add_executable(example_09-04 example_09-04.cpp)


target_link_libraries(clion_opencv_app ${OpenCV_LIBS})
target_link_libraries(example_09-01 ${OpenCV_LIBS})
target_link_libraries(example_09-02 ${OpenCV_LIBS})
target_link_libraries(example_09-03 ${OpenCV_LIBS})
target_link_libraries(example_09-04 ${OpenCV_LIBS} ${OPENGL_LIBRARIES})