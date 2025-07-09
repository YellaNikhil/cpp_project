cmake_minimum_required(VERSION 2.8)
project(basicmath)
add_library(basicmath adder.cpp)
set_target_properties(basicmath PROPERTIES PUBLIC_HEADER adder.h) 
install(TARGETS basicmath LIBRARY DESTINATION lib 
        PUBLIC_HEADER DESTINATION include) # installed all the libaries and headers into the linux system /usr/local/include or /bin