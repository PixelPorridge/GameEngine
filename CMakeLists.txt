cmake_minimum_required(VERSION 3.31)
project(engine)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE
    # Components
    src/components/camera.cpp
    src/components/camera.h
    src/components/sprite.cpp
    src/components/sprite.h
    src/components/transform.cpp
    src/components/transform.h

    # Core
    src/core/core.h

    # Maths
    src/maths/colour.cpp
    src/maths/colour.h
    src/maths/maths.h
    src/maths/matrix4.cpp
    src/maths/matrix4.h
    src/maths/vector2.cpp
    src/maths/vector2.h
    src/maths/vector3.cpp
    src/maths/vector3.h
    src/maths/vector4.cpp
    src/maths/vector4.h

    # OpenGL
    src/opengl/element_buffer.cpp
    src/opengl/element_buffer.h
    src/opengl/program.cpp
    src/opengl/program.h
    src/opengl/shader.cpp
    src/opengl/shader.h
    src/opengl/texture.cpp
    src/opengl/texture.h
    src/opengl/vertex_array.cpp
    src/opengl/vertex_array.h
    src/opengl/vertex_buffer_layout.cpp
    src/opengl/vertex_buffer_layout.h
    src/opengl/vertex_buffer.cpp
    src/opengl/vertex_buffer.h

    # Systems
    src/systems/window.cpp
    src/systems/window.h
    src/systems/renderer.cpp
    src/systems/renderer.h

    # Utils
    src/utils/debug.h
)

target_include_directories(${PROJECT_NAME} PUBLIC src/)

# Glad
add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)

# GLFW
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

# stb
add_subdirectory(external/stb)
target_link_libraries(${PROJECT_NAME} PUBLIC stb)