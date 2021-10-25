cmake_minimum_required(VERSION 3.8)

project(intersect)

enable_language(CXX)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS -Wall)

set(APP_INCLUDES include)
set(APP_TESTS 
	tests/point-test.cpp
	tests/vector-test.cpp
	tests/main-test.cpp)

set(APP_SOURCES
	source/point.cpp
	source/vector.cpp
	source/line.cpp
	source/plane.cpp
	source/triangle.cpp)


add_executable(${PROJECT_NAME} ${APP_SOURCES} ${APP_TESTS})
target_include_directories(${PROJECT_NAME} PRIVATE ${APP_INCLUDES} ${GTEST_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} -pthread)
enable_testing()
