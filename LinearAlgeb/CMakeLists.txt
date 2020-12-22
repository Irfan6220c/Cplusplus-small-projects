cmake_minimum_required(VERSION "3.19.1")

project("LinearAlg")    

add_executable("${PROJECT_NAME}" "main.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "main.cpp" DESTINATION src)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/inc")
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )