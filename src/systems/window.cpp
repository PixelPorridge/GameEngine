#include "window.h"

Window::Window(int width, int height, const std::string& title) {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(glfw_window);

	glfwSetFramebufferSizeCallback(glfw_window, on_viewport_resized);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
}

void Window::run() {
	while (!glfwWindowShouldClose(glfw_window)) {
		float current_frame = (float)glfwGetTime();
		delta = current_frame - last_frame;
		last_frame = current_frame;

		glClearColor(background_colour.r, background_colour.g, background_colour.b, background_colour.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();

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

Vector2 Window::get_mouse_world_position(const Camera& camera) const {
	int width, height;
	glfwGetFramebufferSize(glfw_window, &width, &height);

	// The transformation is calculated by interting the view matrix from Renderer.cpp
	// This is done by performing the operations in reverse order, and inverting some multiplicative parts
	Matrix4 inverse_view = Matrix4::identity();

	inverse_view.translate(Vector3(camera.position, 0));
	inverse_view.scale(Vector3(1 / camera.zoom.x, 1 / camera.zoom.y, 1));
	inverse_view.rotate(camera.rotation, Vector3(0, 0, 1));

	Vector2 offset = -camera.offset * camera.zoom;

	if (camera.centered) {
		offset.x += width / 2.0f;
		offset.y += height / 2.0f;
	}

	inverse_view.translate(Vector3(-offset, 0));

	return inverse_view * get_mouse_viewport_position();
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