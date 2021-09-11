cmake_minimum_required(VERSION 3.20)

project(VideoProcessing)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)

file(GLOB_RECURSE SOURCE_FILES *.cpp)
file(GLOB_RECURSE RESOURCE_FILES *.ui)
file(GLOB_RECURSE HEADER_FILES *.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${RESOURCE_FILES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)
