cmake_minimum_required(VERSION 3.10)
project(FFmpegProject CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(AVFORMAT REQUIRED libavformat)
pkg_check_modules(AVCODEC REQUIRED libavcodec)
pkg_check_modules(AVUTIL REQUIRED libavutil)

include_directories(${AVFORMAT_INCLUDE_DIRS} ${AVCODEC_INCLUDE_DIRS} ${AVUTIL_INCLUDE_DIRS})
link_directories(${AVFORMAT_LIBRARY_DIRS} ${AVCODEC_LIBRARY_DIRS} ${AVUTIL_LIBRARY_DIRS})

add_executable(video_info src/main.cpp)
target_link_libraries(video_info ${AVFORMAT_LIBRARIES} ${AVCODEC_LIBRARIES} ${AVUTIL_LIBRARIES})