cmake_minimum_required(VERSION 3.10)

# Project name and version
project(3DRenderer VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the executable
add_executable(3DRenderer src/main.cpp src/renderer.cpp src/vector3.cpp src/matrix4.cpp src/tests.cpp)

# Include SDL2 headers and link libraries
include_directories(C:/msys64/mingw64/include/SDL2)
link_directories(C:/msys64/mingw64/lib)

# Link SDL2 libraries
target_link_libraries(3DRenderer mingw32 SDL2main SDL2)

# Include the headers in the include directory
include_directories(include)

# Add Windows-specific options
if(WIN32)
    target_link_options(3DRenderer PRIVATE)
endif()
