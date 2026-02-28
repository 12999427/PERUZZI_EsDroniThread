cmake_minimum_required(VERSION 4.1)
project(PERUZZI_EsDroniThread)

set(CMAKE_CXX_STANDARD 20)

add_executable(PERUZZI_EsDroniThread main.cpp
        SDK.cpp
        SDK.h
        Scrittore.cpp
        Scrittore.h
        Lettore.cpp
        Lettore.h
)
