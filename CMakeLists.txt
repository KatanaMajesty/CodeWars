cmake_minimum_required(VERSION 3.2.0)
project(codewars VERSION 0.0.1 LANGUAGES C CXX)

find_package(Git REQUIRED)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if (GIT_SUBMODULE)
        message(STATUS "Updating git submodules")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR 
            "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

set (CMAKE_CXX_STANDARD 17)
include_directories(igloo) # unit testing

set(CODEWARS_KYUS
    katas
)

foreach(kyudir IN LISTS CODEWARS_KYUS)
    add_subdirectory(${kyudir})
    message(STATUS "Added ${kyudir}")
endforeach()

