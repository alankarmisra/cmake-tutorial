cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)

install(TARGETS HelloWorld DESTINATION .)

set(CPACK_PACKAGE_NAME "HelloWorld")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "A simple program packaged with CPack")
set(CPACK_GENERATOR "DragNDrop;TGZ")
include(CPack)
