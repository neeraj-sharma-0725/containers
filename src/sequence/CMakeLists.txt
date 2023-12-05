add_library(sequence array_list.c)

target_include_directories(sequence PUBLIC ${CMAKE_SOURCE_DIR}/include)