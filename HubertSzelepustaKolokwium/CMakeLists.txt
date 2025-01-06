cmake_minimum_required(VERSION 3.29)
project(HubertSzelepustaKolokwium)

set(CMAKE_CXX_STANDARD 20)

add_executable(HubertSzelepustaKolokwium main.cpp
        subject.cpp
        subject.h
        Student.h
        FunktorStudenta.h
)
