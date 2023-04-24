cmake_minimum_required(VERSION 3.25)
project(tasks_week3_binyamin_shouraki)

set(CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()

add_executable(tasks_week3_binyamin_shouraki)
add_subdirectory (include)
add_subdirectory (src)
