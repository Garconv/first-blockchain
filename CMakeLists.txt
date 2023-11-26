cmake_minimum_required(VERSION 3.13)  

set(PROJECT_NAME "first_blockchain")
project(${PROJECT_NAME})               


FILE(GLOB SRCS "${CMAKE_CURRENT_LIST_DIR}/src/blockchain/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} ssl crypto)