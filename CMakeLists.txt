cmake_minimum_required(VERSION 3.10)

project(Raytracer VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(output src/main.cpp)

target_link_libraries(output user32 gdi32 opengl32 gdiplus Shlwapi dwmapi stdc++fs)

# If you want to build a static executable (optional)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
