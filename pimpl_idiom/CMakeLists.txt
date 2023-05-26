cmake_minimum_required(VERSION 3.0.0)
project(pimpl VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Dog Dog.h Dog.cpp)

add_executable(pimpl main.cpp Dog.h Dog.cpp)

target_link_libraries(pimpl PRIVATE Dog)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
