cmake_minimum_required (VERSION 2.8.12)
project (dsa-playground)

include_directories(./include ./src)

add_executable(main test/main.c)