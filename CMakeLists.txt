cmake_minimum_required(VERSION 3.13)
project(cpp_project)
add_executable(cpp_project main.cpp)

add_subdirectory(sdk/cpp)

add_subdirectory(external/glfw)
# target_link_directories(cpp_project PRIVATE ${CMAKE_SOURCE_DIR}/sdk/cpp/build/)
target_include_directories(${PROJECT_NAME} 
    PRIVATE sdk/app
    PRIVATE external/glfw/include)

target_link_directories(${PROJECT_NAME} 
    PRIVATE sdk/app
    PRIVATE external/glfw/src)

target_link_libraries(cpp_project basicmath glfw)
