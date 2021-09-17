cmake_minimum_required(VERSION 3.16)
project(test VERSION 0.1.0)

#add_library(sfml-sys SHARED IMPORTED)
#set_property(TARGET sfml-gra PROPERTY IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/libs/SFML/lib/libsfml-graphics.so.2.5.1")
#target_link_libraries(test PRIVATE sfml-sys)

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


find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
add_executable(test main.cpp)
target_link_libraries(test sfml-graphics sfml-audio)