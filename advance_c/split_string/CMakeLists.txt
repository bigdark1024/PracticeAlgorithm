project(TTT)
cmake_minimum_required(VERSION 3.13.0)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
aux_source_directory(. PROBLEMS)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_C_STANDARD 11)

foreach(PROBLEM ${PROBLEMS})
    get_filename_component(PROBLEM_NAME ${PROBLEM} NAME_WE)
    add_executable(${PROBLEM_NAME} ${PROBLEM})
    target_link_libraries(
        ${PROBLEM_NAME}
        ${GTEST_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
    )
endforeach()
