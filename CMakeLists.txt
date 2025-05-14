cmake_minimum_required(VERSION 4.0)
project(engine)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    src/engine.cpp
    src/engine.h

    src/components/transform.cpp
    src/components/transform.h

    src/maths/maths.h
    src/maths/matrix4.cpp
    src/maths/matrix4.h
    src/maths/vector2.cpp
    src/maths/vector2.h
    src/maths/vector3.cpp
    src/maths/vector3.h
    src/maths/vector4.cpp
    src/maths/vector4.h

    src/objects/camera.cpp
    src/objects/camera.h

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
)

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    PRIVATE
)