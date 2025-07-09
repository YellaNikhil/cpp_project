cmake_minimum_required(VERSION 3.13)
project(cpp_project)
add_executable(cpp_project main.cpp)

# ---------------- DOWNLOAD ALL THE SUBMODULES ------------------
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

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
