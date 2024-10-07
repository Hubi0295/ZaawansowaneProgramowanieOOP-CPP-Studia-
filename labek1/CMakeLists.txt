cmake_minimum_required(VERSION 3.29)
project(labek1)

set(CMAKE_CXX_STANDARD 11)

add_executable(labek1 main.cpp
        Person.cpp
        Person.h
        Teacher.cpp
        Teacher.h
        Student.cpp
        Student.h
        Animal.cpp
        Animal.h
        Dog.cpp
        Dog.h)
