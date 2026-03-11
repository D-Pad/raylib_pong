cmake_minimum_required(VERSION 3.11)
project(PongClone)

# Fetch and build raylib as a static library
include(FetchContent)
set(RAYLIB_VERSION 5.5)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

add_executable(
	pong
	src/game_objects/Ball.cpp
	src/core/Cleanup.cpp
	src/core/Init.cpp
	src/core/Core.cpp
	src/main.cpp
)

# Link the static library
target_link_libraries(pong PRIVATE raylib)

