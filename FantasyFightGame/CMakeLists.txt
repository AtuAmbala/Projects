cmake_minimum_required(VERSION 3.5)

project(solution)

find_package(GTest)

if (WIN32)
  # thank you Microsoft for making MSVC's compiler flags different than all the others
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std:c++20")
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
ELSE()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -std=c++20")
ENDIF()

# yea this is dumb but don't worry about it
file(GLOB sources
  "sources/*.cpp"
  "sources/**/*.cpp"
  "sources/**/**/*.cpp"
  "sources/**/**/**/*.cpp"
  "sources/**/**/**/**/*.cpp"
  "sources/**/**/**/**/**/*.cpp"
  "sources/**/**/**/**/**/**/*.cpp"
  "sources/**/**/**/**/**/**/**/*.cpp"
  "sources/**/**/**/**/**/**/**/**/*.cpp"
  "sources/**/**/**/**/**/**/**/**/**/*.cpp")

add_executable(project ${sources})
enable_testing()
include(GoogleTest)

list(FILTER sources EXCLUDE REGEX ".*Main\\.cpp$")

add_executable(main_test "tests/MainTest.cpp" ${sources})
target_link_libraries(main_test GTest::gtest_main)
gtest_discover_tests(main_test)
