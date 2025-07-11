cmake_minimum_required(VERSION 3.13)

project(CPP_PROJECT VERSION 1.0)

option(USE_ADDER "To use adder library which adds two variables of interger or float" ON)

if(USE_ADDER)
    add_subdirectory(sdk/cpp)

    list(APPEND EXTRA_INCLUDES_DIR "sdk/app")
    list(APPEND EXTRA_LINK_DIR "sdk/app")
    list(APPEND EXTRA_LINK_LIBS basicmath)

endif()

configure_file(${PROJECT_NAME}Config.h.in ${PROJECT_NAME}Config.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

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

add_subdirectory(external/glfw)

#To include the header files to the target. specify how they accessible by PUBLIC or PRIVATE
# PUBLIC - .h or source files are accessible and used for building the target.
# PRIVATE - .h or source files are not accessible. but only used for building the target.
target_include_directories(${PROJECT_NAME} 
    PRIVATE external/glfw/include
    ${EXTRA_INCLUDES_DIR}    
)


#To link the SOURCE file directories to the target. specify how they accessible by PUBLIC or PRIVATE
target_link_directories(${PROJECT_NAME} 
    PRIVATE external/glfw/src
    ${EXTRA_LINK_DIR}
)

target_link_libraries(${PROJECT_NAME} ${EXTRA_LINK_LIBS} glfw)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h" DESTINATION include)