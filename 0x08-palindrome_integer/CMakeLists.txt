cmake_minimum_required(VERSION 3.14)

project(Palindrome_Integer C)

set(CMAKE_C_FLAGS "-g -ggdb -std=c90 -Wall -Werror -Wextra -pedantic")

add_executable(main
        0-main.c
        0-is_palindrome.c
        )
