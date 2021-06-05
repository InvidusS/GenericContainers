cmake_minimum_required(VERSION 3.10)
project (GenericContainers)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE GENERIC_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(generic_src ${GENERIC_SRC})
target_include_directories(generic_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(GenericContainers ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(GenericContainers generic_src)

file(GLOB_RECURSE GENERIC_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${GENERIC_TEST_SRC})
target_link_libraries(tests generic_src)
target_link_libraries(tests ${CONAN_LIBS})
