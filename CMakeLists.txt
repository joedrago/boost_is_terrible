cmake_minimum_required(VERSION 2.6)
project(terrible)

set(BOOST_ROOT               ${CMAKE_SOURCE_DIR}/../boost_1_50_0)
set(Boost_USE_STATIC_LIBS    ON)
set(Boost_USE_MULTITHREADED  ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.50.0 COMPONENTS
    date_time
    filesystem
    system
)
if(Boost_FOUND)
   include_directories(${Boost_INCLUDE_DIRS})
endif()

if(UNIX)
    add_definitions(-g) # dat debugging
endif()

add_subdirectory(terrible)
