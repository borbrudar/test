cmake_minimum_required(VERSION 3.16)
project(test VERSION 0.1.0)

#add_library(sfml-sys SHARED IMPORTED)
#add_library(sfml-win SHARED IMPORTED)
#add_library(sfml-gra SHARED IMPORTED)

#set_property(TARGET sfml-sys PROPERTY IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/libs/SFML/lib/libsfml-system.so.2.5.1")
#set_property(TARGET sfml-win PROPERTY IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/libs/SFML/lib/libsfml-window.so.2.5.1")
#set_property(TARGET sfml-gra PROPERTY IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/libs/SFML/lib/libsfml-graphics.so.2.5.1")


#set(SFML_DIR "${PROJECT_SOURCE_DIR}/libs/SFML/lib/cmake/")
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(test main.cpp)
#target_link_libraries(test PRIVATE sfml-sys)
#target_link_libraries(test PRIVATE sfml-win)
#target_link_libraries(test PRIVATE sfml-gra)

target_include_directories(test PUBLIC "${PROJECT_SOURCE_DIR}/libs/SFML/include/")
target_link_libraries(test sfml-graphics sfml-audio)