#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb/stb_image.h"

#include <string>
#include <functional>

class Engine {
private:
	GLFWwindow* window;

	float last_frame = 0;

	std::function<void(float)> update_callback;
	std::function<void()> render_callback;

public:
	Engine(int width, int height, const std::string& title);

	void run();

	static inline float get_time() {
		return (float)glfwGetTime();
	}

	static inline void draw_triangles() {
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void set_update_callback(std::function<void(float)> callback);
	void set_render_callback(std::function<void()> callback);

private:
	static void on_framebuffer_resized(GLFWwindow* window, int width, int height);
};