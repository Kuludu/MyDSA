cmake_minimum_required (VERSION 3.15)

project (SingleLinkedListExample)

set (CMAKE_CXX_STANDARD 11)

aux_source_directory(. SLL_SRCS)

add_executable(singlelinkedlist ${SLL_SRCS})
