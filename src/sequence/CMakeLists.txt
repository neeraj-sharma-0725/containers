list(APPEND files array_list.c)
list(APPEND files linked_list.c)
add_library(sequence ${files})

target_include_directories(sequence PUBLIC ${CMAKE_SOURCE_DIR}/include)