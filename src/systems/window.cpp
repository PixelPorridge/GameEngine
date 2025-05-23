#include "window.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb/stb_image.h"

Window::Window(int width, int height, const std::string& title) {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

	if (glfw_window == nullptr) {
		Debug::log("Failed to create GLFW window!", Debug::ERROR);
		return;
	}

	glfwMakeContextCurrent(glfw_window);
	glfwSetWindowUserPointer(glfw_window, this);
	glfwSetFramebufferSizeCallback(glfw_window, on_viewport_resized);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		Debug::log("Failed to initialise Glad!", Debug::ERROR);
		return;
	}

	glViewport(0, 0, width, height);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Window::run() {
	while (!glfwWindowShouldClose(glfw_window)) {
		float current_frame = (float)glfwGetTime();
		delta = current_frame - last_frame;
		last_frame = current_frame;

		glfwPollEvents();

		glClearColor(background_colour.r, background_colour.g, background_colour.b, background_colour.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (update_callback != nullptr) {
			update_callback();
		}

		glfwSwapBuffers(glfw_window);
	}

	glfwTerminate();
}

void Window::close() {
	glfwSetWindowShouldClose(glfw_window, true);
}

float Window::get_time() const {
	return (float)glfwGetTime();
}

float Window::get_delta() const {
	return delta;
}

Vector2 Window::get_size() const {
	int width, height;
	glfwGetWindowSize(glfw_window, &width, &height);

	return Vector2(width, height);
}

Vector2 Window::get_viewport_size() const {
	int width, height;
	glfwGetFramebufferSize(glfw_window, &width, &height);

	return Vector2(width, height);
}

Vector2 Window::get_mouse_position() const {
	double mouse_x, mouse_y;
	glfwGetCursorPos(glfw_window, &mouse_x, &mouse_y);

	return Vector2(mouse_x, mouse_y);
}

Vector2 Window::get_mouse_viewport_position() const {
	float scale_x, scale_y;
	glfwGetWindowContentScale(glfw_window, &scale_x, &scale_y);

	double mouse_x, mouse_y;
	glfwGetCursorPos(glfw_window, &mouse_x, &mouse_y);

	return Vector2(mouse_x * scale_x, mouse_y * scale_y);
}

void Window::set_size(int width, int height) {
	glfwSetWindowSize(glfw_window, width, height);
}

void Window::set_viewport_size(int width, int height) {
	float scale_x, scale_y;
	glfwGetWindowContentScale(glfw_window, &scale_x, &scale_y);

	glfwSetWindowSize(glfw_window, width / scale_x, height / scale_y);
}

void Window::set_title(const std::string& title) {
	glfwSetWindowTitle(glfw_window, title.c_str());
}

void Window::set_icon(const std::vector<std::string>& paths) {
	std::vector<GLFWimage> images;

	for (const std::string& path : paths) {
		GLFWimage image;
		image.pixels = stbi_load(path.c_str(), &image.width, &image.height, 0, 4);

		if (image.pixels == nullptr) {
			Debug::log("Failed to load window icon: " + path, Debug::ERROR);
			stbi_image_free(image.pixels);
			continue;
		}

		images.push_back(image);
	}

	glfwSetWindowIcon(glfw_window, images.size(), &images[0]);

	for (const GLFWimage& image : images) {
		stbi_image_free(image.pixels);
	}
}

void Window::set_resizable(bool resizable) {
	glfwSetWindowAttrib(glfw_window, GLFW_RESIZABLE, resizable);
}

void Window::set_borderless(bool borderless) {
	glfwSetWindowAttrib(glfw_window, GLFW_DECORATED, borderless);
}

void Window::set_background_colour(const Colour& colour) {
	background_colour = colour;
}

void Window::set_update_callback(std::function<void()> callback) {
	update_callback = callback;
}

void Window::on_viewport_resized(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}