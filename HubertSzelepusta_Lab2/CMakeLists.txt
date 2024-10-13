cmake_minimum_required(VERSION 3.29)
project(HubertSzelepusta_Lab2)

set(CMAKE_CXX_STANDARD 11)

add_executable(HubertSzelepusta_Lab2 main.cpp
        Figure.cpp
        Figure.h
        Square.cpp
        Square.h
        Circle.cpp
        Circle.h
        Developer.cpp
        Developer.h
        Employee.cpp
        Employee.h
        TeamLeader.cpp
        TeamLeader.h
        Bufor.cpp
        Bufor.h
        meanBufor.cpp
        meanBufor.h
        maxBufor.cpp
        maxBufor.h
)
