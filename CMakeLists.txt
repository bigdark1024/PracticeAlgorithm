cmake_minimum_required(VERSION 3.13.0)
project(PracticeAlgorithm VERSION 0.1.0)

# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(TOP_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})
set(PUB_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR})

# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# enable_testing()
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
   add_compile_options(-fprofile-instr-generate -fcoverage-mapping)
   add_link_options(-fprofile-instr-generate)
   #Uncomment in case of linker errors
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
   add_compile_options(--coverage)
   #Uncomment in case of linker errors
   link_libraries(gcov)
endif ()

if (WIN32)
    message(STATUS "Detected Windows platform")
elseif (UNIX)
    message(STATUS "Detected UNIX platform")
elseif (APPLE)
    message(STATUS "Detected MacOS platform")
else ()
    message(FATAL_ERROR "Unsupported platform")
endif ()

include_directories(${CMAKE_SOURCE_DIR}/include)

MACRO(SUBDIRLIST result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")
    FOREACH (child ${children})
        IF (IS_DIRECTORY ${curdir}/${child})
            LIST(APPEND dirlist ${child})
        ENDIF ()
    ENDFOREACH ()
    SET(${result} ${dirlist})
ENDMACRO()


add_subdirectory(include)

SUBDIRLIST(problems ${CMAKE_CURRENT_SOURCE_DIR}/problems)
foreach (problem ${problems})
    add_subdirectory(problems/${problem})
endforeach ()

SUBDIRLIST(cc_problems ${CMAKE_CURRENT_SOURCE_DIR}/advance_c)
foreach (problem ${cc_problems})
    add_subdirectory(advance_c/${problem})
endforeach ()