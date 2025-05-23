#pragma once

#include "maths/vector2.h"
#include "maths/colour.h"
#include "core/debug.h"

#include <string>
#include <vector>
#include <functional>

class GLFWwindow;

class Window {
private:
	GLFWwindow* glfw_window;

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
	Vector2 get_viewport_size() const;
	Vector2 get_mouse_position() const;
	Vector2 get_mouse_viewport_position() const;

	void set_size(int width, int height);
	void set_viewport_size(int width, int height);
	void set_title(const std::string& title);
	void set_icon(const std::vector<std::string>& paths);
	void set_resizable(bool resizable);
	void set_borderless(bool borderless);
	void set_background_colour(const Colour& colour);

	void set_update_callback(std::function<void()> callback);

private:
	static void on_viewport_resized(GLFWwindow* window, int width, int height);
};