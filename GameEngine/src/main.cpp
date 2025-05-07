#include "main.h"

int main() {
	// Initialise GLFW window
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Game Engine", nullptr, nullptr);

	if (window == nullptr) {
		std::cout << "Failed to create GLFW window!" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Initialise Glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialise Glad!" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);

	Program program("src/shaders/default.vert", "src/shaders/default.frag");

	std::vector<float> vertices = {
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f
	};

	std::vector<int> indices = {
		0, 1, 3,
		1, 2, 3
	};

	VertexBuffer vertex_buffer(vertices);
	VertexBufferLayout vertex_buffer_layout;
	vertex_buffer_layout.push<GLfloat>(3);
	vertex_buffer_layout.push<GLfloat>(3);

	ElementBuffer element_buffer(indices);

	VertexArray vertex_array;
	vertex_array.link_vertex_buffer(vertex_buffer, vertex_buffer_layout);
	vertex_array.link_element_buffer(element_buffer);

	// Window render loop
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		process_input(window);

		glClearColor(0.25f, 0.4f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		program.use();
		vertex_array.bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		glfwSwapBuffers(window);
	}
	
	// Cleanup
	glfwTerminate();
	return 0;
}

void process_input(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}