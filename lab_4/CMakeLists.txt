cmake_minimum_required(VERSION 3.29)
project(lab_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_4 main.cpp
        Even.cpp
        Even.h
        Student.cpp
        Student.h
        Compare.cpp
        Compare.h
        Address.cpp
        Address.h
        Citizen.cpp
        Citizen.h
        City.cpp
        City.h
        CompareByNumberCitizens.cpp
        CompareByNumberCitizens.h
        CompareByNumberDigits.cpp
        CompareByNumberDigits.h
        CompareBySumDigits.cpp
        CompareBySumDigits.h)
