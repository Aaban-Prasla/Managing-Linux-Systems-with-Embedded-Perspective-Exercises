cmake_minimum_required(VERSION 3.22.1)

project(
	random_generator
	VERSION 0.4
	DESCRIPTION "Generates random numbers based on the parameters that are given."
	LANGUAGES C
)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
	C_files/main.c
	C_files/random_generator.c
	C_files/error_handling.c)

target_include_directories(${PROJECT_NAME} PRIVATE
	Header_files
)

target_compile_options(${PROJECT_NAME} PRIVATE
	-Wall
	-Wextra
	-Wfatal-errors
	-Wpedantic
)
