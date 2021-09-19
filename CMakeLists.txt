cmake_minimum_required(VERSION 3.16)
project(myProject VERSION 0.1.0)

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
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/SFML/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()


add_subdirectory("${PROJECT_SOURCE_DIR}/external/SFML")
add_subdirectory("${PROJECT_SOURCE_DIR}/external/catch")


add_executable(myProject main.cpp foo.cpp foo.h)
target_link_libraries(myProject sfml-graphics sfml-audio)

enable_testing()
add_executable(myTest tests/test.cpp foo.cpp foo.h)
target_link_libraries(myTest PUBLIC Catch2::Catch2WithMain)

target_include_directories(myTest PUBLIC "${PROJECT_SOURCE_DIR}")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/external/catch/extras)
include(CTest)
include(Catch)
catch_discover_tests(myTest)

