cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/html.build)

# WT PROJECT
project(hello CXX)
find_package(Wt REQUIRED Wt HTTP)
add_executable(hello app/main.cpp)
target_link_libraries(hello
  Wt::Wt
  Wt::HTTP
)

# UNIT TEST
enable_testing()
find_package(GTest REQUIRED)
add_executable( test.t test/test.cpp )
target_link_libraries(test.t GTest::GTest GTest::Main)
add_test( test.t test.t )
    
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/html_to_cpp.build.stamp
    COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/html_to_cpp.py ${CMAKE_CURRENT_SOURCE_DIR}/app/html ${CMAKE_CURRENT_SOURCE_DIR}/html.build
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/app/html
    COMMENT "Rebuilding html target because html files in the directory have changed"
)

add_custom_target(
  html_rebuild_target ALL
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/html_to_cpp.build.stamp
)

add_dependencies(hello html_rebuild_target)
