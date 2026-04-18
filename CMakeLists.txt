cmake_minimum_required(VERSION 3.20)
project(cpp_learning LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ──────────────────────────────────────────────
# Compiler warning flags
# ──────────────────────────────────────────────
if(MSVC)
    add_compile_options(/W4 /permissive- /EHsc)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ──────────────────────────────────────────────
# Targets
# ──────────────────────────────────────────────

# playground — свободная зона для экспериментов
add_executable(playground playground/main.cpp)

# lesson 01 — task01_hello
add_executable(lesson_01_task01_hello lessons/01_basics/src/task01_hello.cpp)
