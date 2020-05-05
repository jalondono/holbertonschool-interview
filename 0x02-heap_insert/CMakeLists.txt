cmake_minimum_required(VERSION 3.14)

project(Linked_List_Interview C)

set(CMAKE_C_FLAGS "-g -ggdb -std=c90 -Wall -Werror -Wextra -pedantic")

add_executable(main
        0-binary_tree_node.c
        0-main.c
        binary_tree_print.c
        )
