cmake_minimum_required(VERSION 3.29)
project(lab_6)

set(CMAKE_CXX_STANDARD 20)


add_executable(lab_6 main.cpp
        Person.cpp
        Person.h
        Print.cpp
        Print.h
        Operation.cpp
        Operation.h
        Contact.cpp
        Contact.h
        Contacts.cpp
        Contacts.h
        main.cpp)
set(BOOST_ROOT "..\\boost_1_83_0")
find_package(Boost 1.83.0)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")
include_directories(${Boost_INCLUDE_DIR})
