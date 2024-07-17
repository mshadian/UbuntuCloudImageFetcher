cmake_minimum_required(VERSION 3.10)
project(UbuntuCloudImageFetcher)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/local/include)

link_directories(/usr/local/lib)

add_executable(UbuntuCloudImageFetcher main.cpp IUbuntuCloudImageFetcher.h UbuntuCloudImageFetcher.cpp)

target_link_libraries(UbuntuCloudImageFetcher curl jsoncpp)