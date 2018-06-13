cmake_minimum_required(VERSION 2.8.9)
project(system-asset)

set(CMAKE_CXX_STANDARD 11)

link_libraries(asset curl)

add_executable(asset *.cpp)

install(TARGET asset DESTINATION bin)



