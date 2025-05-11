#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <vector>
#include <numbers>

#include "opengl/program.h"
#include "opengl/vertex_buffer.h"
#include "opengl/element_buffer.h"
#include "opengl/vertex_array.h"
#include "opengl/vertex_buffer_layout.h"
#include "opengl/texture.h"
#include "maths/matrix4.h"
#include "maths/vector3.h"
#include "maths/maths.h"

void process_input(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);