cmake_minimum_required(VERSION 3.28)
project(Taller3_ED)

set(CMAKE_CXX_STANDARD 17)

add_executable(Taller3_ED main.cpp
        Sistema.cpp
        Sistema.h
        Laberinto.cpp
        Laberinto.h
        Thread.cpp
        Thread.h
)
