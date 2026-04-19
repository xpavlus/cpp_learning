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

# lesson 03 — task01_control_flow
add_executable(lesson_03_task01_control_flow lessons/03_control_flow/src/task01_control_flow.cpp)

# lesson 04 — task01_functions
add_executable(lesson_04_task01_functions lessons/04_functions/src/task01_functions.cpp)

# lesson 05 — task01_oop
add_executable(lesson_05_task01_oop lessons/05_oop/src/task01_oop.cpp)
