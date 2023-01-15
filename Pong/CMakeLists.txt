cmake_minimum_required(VERSION 3.10)

set(NAME "Pong")

# Project name
project(${NAME} VERSION 1.0)

# Add exectuable
add_executable(${NAME}
  "${CMAKE_SOURCE_DIR}/src/main.cpp"
  "${CMAKE_SOURCE_DIR}/src/paddle.cpp"
  "${CMAKE_SOURCE_DIR}/src/ball.cpp")

target_include_directories(${NAME}
               PUBLIC
               "${CMAKE_SOURCE_DIR}/inc"
               "/usr/include/SFML")

if (UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
  # Specify C++ standard
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

  target_link_libraries(${NAME}
    "/usr/lib/x86_64-linux-gnu/libsfml-system.so"
    "/usr/lib/x86_64-linux-gnu/libsfml-graphics.so"
    "/usr/lib/x86_64-linux-gnu/libsfml-window.so")
#    "/usr/lib/x86_64-linux-gnu/libsfml-network.so")


endif (UNIX)

# Make top-level CMakeLists aware of sub-CMakeLists
#add_subdirectory("${CMAKE_SOURCE_DIR}/src/Pong")

#target_link_libraries(TinyRenderer TGAImage)
#target_link_libraries(TinyRenderer "${CMAKE_SOURCE_DIR}/lib/libLogger.a")
