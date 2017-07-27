cmake_minimum_required(VERSION 3.7)
project(PCA9685)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCE_FILES src/PCA9685.cpp src/PCA9685.h)

set(SOURCE_FILES ${SOURCE_FILES})
add_library(PCA9685 ${SOURCE_FILES})

install(TARGETS PCA9685 DESTINATION lib)
install(FILES src/PCA9685.h DESTINATION include)

add_executable(PCA9685_test test/main.cpp)
target_link_libraries(PCA9685_test PCA9685)