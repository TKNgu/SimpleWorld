cmake_minimum_required(VERSION 3.10.2)
include(ExternalProject)
set(CMAKE_EXPORT_COMPINLE_COMMANDS ON)
set(CMAKE_EXE_LINKER_FLAGS "-no-pie")
set(CMAKE_BUILD_TYPE debug)

project(SimpleWorld VERSION 0.1.0 LANGUAGES C DESCRIPTION "SimpleWorld")
add_compile_definitions(DEBUG)

# ExternalProject_add(libraylib
#     GIT_REPOSITORY git@github.com:raysan5/raylib.git
#     GIT_TAG 5.5
#     SOURCE_DIR ${CMAKE_SOURCE_DIR}/lib/raylib
#     CMAKE_ARGS
# 	   -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_SOURCE_DIR}/lib/local)

include_directories(
    ${CMAKE_SOURCE_DIR}/lib/local/include/
)

link_directories(
    ${CMAKE_SOURCE_DIR}/lib/local/lib/
)

file(GLOB SRC ${CMAKE_SOURCE_DIR}/src/*.c)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/local/lib/libraylib.a m)
add_custom_target(run ${CMAKE_COMMAND} -E env "LD_LIBRARY_PATH=${CMAKE_SOURCE_DIR}/lib/local/lib/"
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}
  DEPENDS ${CMAKE_PROJECT_NAME}
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
