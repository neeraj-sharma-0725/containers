cmake_minimum_required(VERSION 3.25.1 FATAL_ERROR)

project(containers)

add_subdirectory(src/sequence)
add_subdirectory(src/common)

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PUBLIC include)
list(APPEND LIBS sequence)
list(APPEND LIBS common)
target_link_libraries(${PROJECT_NAME} PUBLIC ${LIBS})