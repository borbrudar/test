cmake_minimum_required(VERSION 3.16)
project(spark VERSION 0.1.0)

enable_testing()

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


add_executable(spark main.cpp bruh.cpp bruh.h)
target_link_libraries(spark sfml-graphics sfml-audio)

add_executable(TESTOKUN tests/test.cpp)
target_link_libraries(TESTOKUN PUBLIC Catch2::Catch2WithMain sfml-graphics sfml-audio)

target_include_directories(TESTOKUN PUBLIC "${PROJECT_SOURCE_DIR}")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/external/catch/extras)
include(CTest)
include(Catch)
catch_discover_tests(proj)

#add_test(NAME TESTOKUN COMMAND Test)
