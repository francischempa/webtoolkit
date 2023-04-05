cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

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
