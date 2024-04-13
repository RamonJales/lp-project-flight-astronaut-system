cmake_minimum_required(VERSION 3.15)

project(Flight-Astronaut-System)

add_executable(project 
  main.cpp
  impl/astronaut.cpp 
  impl/flight.cpp
  impl/interface.cpp
)

target_include_directories(project PRIVATE include)