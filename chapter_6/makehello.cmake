add_executable(MakeHello makehello.cpp)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/hello.h
  COMMAND MakeHello ${CMAKE_CURRENT_BINARY_DIR}/hello.h
  DEPENDS MakeHello
  )
