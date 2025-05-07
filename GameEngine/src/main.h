#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <vector>

#include "opengl/program.h"
#include "opengl/vertex_buffer.h"
#include "opengl/element_buffer.h"
#include "opengl/vertex_array.h"
#include "opengl/vertex_buffer_layout.h"
#include "opengl/texture.h"

void process_input(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);