#include "main.h"

int main() {
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

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialise Glad!" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glEnable(GL_DEPTH_TEST);

	stbi_set_flip_vertically_on_load(true);

	std::vector<float> vertices = {
		// Positions         // Colours         // Texture coords
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,  // Bottom left
		-0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,  // Top left
		 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,  // Bottom right
		 0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f,  // Top right
	};

	std::vector<int> indices = {
		0, 1, 2,
		1, 2, 3
	};

	VertexBuffer vertex_buffer(vertices);
	VertexBufferLayout vertex_buffer_layout;
	vertex_buffer_layout.push(3);
	vertex_buffer_layout.push(3);
	vertex_buffer_layout.push(2);

	ElementBuffer element_buffer(indices);

	VertexArray vertex_array;
	vertex_array.link_vertex_buffer(vertex_buffer, vertex_buffer_layout);
	vertex_array.link_element_buffer(element_buffer);

	Texture container_texture("assets/textures/container.jpg");
	container_texture.bind(0);

	Texture awesome_face_texture("assets/textures/awesomeface.png");
	awesome_face_texture.bind(1);
	 
	Shader vertex_shader("assets/shaders/default.vert");
	Shader fragment_shader("assets/shaders/default.frag");
	Program program(vertex_shader, fragment_shader);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		process_input(window);

		glClearColor(0.25f, 0.4f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Matrix4 model = Matrix4::identity();
		model.rotate((float)glfwGetTime() * Maths::degrees_to_radians(50), Vector3(0, 0, 1));

		program.set_mat4("model", model);

		program.use();
		vertex_array.bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		glfwSwapBuffers(window);
	}
	
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