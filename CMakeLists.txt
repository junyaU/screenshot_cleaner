cmake_minimum_required(VERSION 3.23)
project(screenshot_cleaner C)

set(CMAKE_C_STANDARD 99)

add_executable(screenshot_cleaner main.c cleaner.c cleaner.h scheduler.c scheduler.h)
