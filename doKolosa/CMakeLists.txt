cmake_minimum_required(VERSION 3.29)
project(doKolosa)

set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT "..\\boost_1_83_0")
find_package(Boost 1.83.0)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")
include_directories(${Boost_INCLUDE_DIR})
add_executable(doKolosa main.cpp
        Parent.cpp
        Parent.h
        Child.cpp
        Child.h
        Figure.cpp
        Figure.h
        Square.cpp
        Square.h
        Circle.cpp
        Circle.h
        Adding.h
        Student.h
        Person.cpp
        Person.h
        Operation.cpp
        Operation.h
        Print.cpp
        Print.h
        Even.cpp
        Even.h
        Compare.cpp
        Compare.h
        Student.cpp
)
