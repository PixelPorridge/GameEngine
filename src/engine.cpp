#include "engine.h"

Engine::Engine(int width, int height, const std::string& title) {
	// GLFW
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, on_framebuffer_resized);

	// OpenGL
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);

	// stb_image
	stbi_set_flip_vertically_on_load(true);
}

void Engine::run() {
	while (!glfwWindowShouldClose(window)) {
		float current_frame = (float)glfwGetTime();
		delta = current_frame - last_frame;
		last_frame = current_frame;

		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();

		if (update_callback != nullptr) {
			update_callback();
		}

		glfwSwapBuffers(window);
	}

	glfwTerminate();
}

float Engine::get_time() const {
	return (float)glfwGetTime();
}

float Engine::get_delta() const {
	return delta;
}

void Engine::set_update_callback(std::function<void()> callback) {
	update_callback = callback;
}

void Engine::on_framebuffer_resized(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}