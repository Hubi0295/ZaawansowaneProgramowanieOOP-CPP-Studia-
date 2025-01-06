cmake_minimum_required(VERSION 3.29)
project(lab_8)

set(CMAKE_CXX_STANDARD 20)
set(BOOST_ROOT "C:\\Users\\Hubert\\CLionProjects\\ZaawansowaneProgramowanieOOP-CPP-Studia-\\boost_1_83_0")
find_package(Boost 1.83.0)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")
include_directories(${Boost_INCLUDE_DIR})
add_executable(lab_8 main.cpp
        Student.cpp
        Student.h
        Comparator.cpp
        Comparator.h)
