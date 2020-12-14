cmake_minimum_required (VERSION 3.10)
set (CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

add_library(GraphoLibrary grafo.cpp)

add_executable(mainApp main.cpp)
target_link_libraries(mainApp GraphoLibrary)

add_executable(unitTestRunner testRunner.cpp)
target_link_libraries(unitTestRunner GraphoLibrary ${GTEST_LIBRARIES} pthread)
