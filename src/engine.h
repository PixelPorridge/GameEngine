#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb/stb_image.h"

#include <string>
#include <functional>

class Engine {
private:
	GLFWwindow* window;

	float delta = 0;
	float last_frame = 0;

	std::function<void()> update_callback;

public:
	Engine(int width, int height, const std::string& title);

	void run();

	float get_time() const;
	float get_delta() const;

	void set_update_callback(std::function<void()> callback);

private:
	static void on_framebuffer_resized(GLFWwindow* window, int width, int height);
};