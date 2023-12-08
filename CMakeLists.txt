cmake_minimum_required(VERSION 2.8.12.2)

project (trashify)

file(GLOB_RECURSE SOURCES "src/*.cpp")


add_executable(trashify main.cpp ${SOURCES})
target_include_directories(trashify PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

