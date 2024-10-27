cmake_minimum_required(VERSION 3.29)
project(zad2)

set(CMAKE_CXX_STANDARD 17)

add_executable(zad2 main.cpp
        Citizen.cpp
        Citizen.h
        City.cpp
        City.h
        Address.cpp
        Address.h)
