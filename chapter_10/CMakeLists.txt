cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

add_executable(HelloWorld main.cpp)

install(TARGETS HelloWorld DESTINATION .)

set(CPACK_PACKAGE_NAME "HelloWorld")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "A simple program packaged with CPack")
set(CPACK_PACKAGE_VENDOR "MyCompany")
set(CPACK_PACKAGE_CONTACT "support@mycompany.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")
install(FILES ${CMAKE_SOURCE_DIR}/LICENSE.txt DESTINATION .)
install(FILES ${CMAKE_SOURCE_DIR}/README.md DESTINATION .)
set(CPACK_GENERATOR "DragNDrop;TGZ")
include(CPack)
