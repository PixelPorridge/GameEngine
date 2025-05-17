#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb/stb_image.h"
#include "maths/vector2.h"
#include "maths/colour.h"

#include <vector>
#include <string>
#include <functional>

class Window {
private:
	GLFWwindow* window;

	float delta = 0;
	float last_frame = 0;
	Colour background_colour;

	std::function<void()> update_callback;

public:
	Window(int width, int height, const std::string& title);

	void run();
	void close();

	float get_time() const;
	float get_delta() const;

	Vector2 get_size() const;
	Vector2 get_mouse_position() const;

	void set_size(int width, int height);
	void set_title(const std::string& title);
	void set_icon(const std::vector<std::string>& paths);
	void set_resizable(bool resizable);
	void set_decorated(bool decorated);
	void set_background_colour(const Colour& colour);

	void set_update_callback(std::function<void()> callback);

private:
	static void on_framebuffer_resized(GLFWwindow* window, int width, int height);
};