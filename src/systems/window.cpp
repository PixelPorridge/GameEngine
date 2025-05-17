#include "window.h"

Window::Window(int width, int height, const std::string& title) {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, on_framebuffer_resized);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);

	stbi_set_flip_vertically_on_load(true);
}

void Window::run() {
	while (!glfwWindowShouldClose(window)) {
		float current_frame = (float)glfwGetTime();
		delta = current_frame - last_frame;
		last_frame = current_frame;

		glClearColor(background_colour.r, background_colour.g, background_colour.b, background_colour.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();

		if (update_callback != nullptr) {
			update_callback();
		}

		glfwSwapBuffers(window);
	}

	glfwTerminate();
}

void Window::close() {
	glfwSetWindowShouldClose(window, true);
}

float Window::get_time() const {
	return (float)glfwGetTime();
}

float Window::get_delta() const {
	return delta;
}

Vector2 Window::get_size() const {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	return Vector2(width, height);
}

Vector2 Window::get_mouse_position() const {
	float scale_x, scale_y;
	glfwGetWindowContentScale(window, &scale_x, &scale_y);

	double mouse_x, mouse_y;
	glfwGetCursorPos(window, &mouse_x, &mouse_y);

	return Vector2(mouse_x * scale_x, mouse_y * scale_y);
}

void Window::set_size(int width, int height) {
	float scale_x, scale_y;
	glfwGetWindowContentScale(window, &scale_x, &scale_y);

	glfwSetWindowSize(window, width / scale_x, height / scale_y);
}

void Window::set_title(const std::string& title) {
	glfwSetWindowTitle(window, title.c_str());
}

void Window::set_icon(const std::vector<std::string>& paths) {
	std::vector<GLFWimage> images;
	stbi_set_flip_vertically_on_load(false);

	for (const std::string& path : paths) {
		GLFWimage image;
		image.pixels = stbi_load(path.c_str(), &image.width, &image.height, 0, 4);
		images.push_back(image);
	}

	stbi_set_flip_vertically_on_load(true);
	glfwSetWindowIcon(window, images.size(), &images[0]);

	for (const GLFWimage& image : images) {
		stbi_image_free(image.pixels);
	}
}

void Window::set_resizable(bool resizable) {
	glfwSetWindowAttrib(window, GLFW_RESIZABLE, resizable);
}

void Window::set_decorated(bool decorated) {
	glfwSetWindowAttrib(window, GLFW_DECORATED, decorated);
}

void Window::set_background_colour(const Colour& colour) {
	background_colour = colour;
}

void Window::set_update_callback(std::function<void()> callback) {
	update_callback = callback;
}

void Window::on_framebuffer_resized(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}