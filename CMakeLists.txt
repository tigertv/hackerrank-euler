cmake_minimum_required (VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -pedantic -O3)

file(GLOB APP_SOURCES "src/*.cpp")
foreach(srcfile ${APP_SOURCES})
	string(REGEX REPLACE "^.*/(.*)\\.cpp$" "\\1" binaryname ${srcfile})
    add_executable(${binaryname} ${srcfile})
endforeach(srcfile ${APP_SOURCES})
