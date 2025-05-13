#include "main.h"

int main() {
	Engine engine = Engine(800, 600, "Game Engine");
	engine.set_update_callback(update);
	engine.run();

	return 0;
}

static void update(float delta) {
	std::vector<float> vertices = {
		// Positions  // Texture
		-0.5f, -0.5f, 0.0f, 0.0f, // Bottom-left
		-0.5f,  0.5f, 0.0f, 1.0f, // Top-left
		 0.5f, -0.5f, 1.0f, 0.0f, // Bottom-right
		 0.5f,  0.5f, 1.0f, 1.0f  // Top-right
	};

	std::vector<int> indices = {
		0, 1, 2, // Bottom-left, top-left, bottom-right
		1, 2, 3  // Top-left, bottom-right, top-right
	};

	VertexBuffer vertex_buffer(vertices);
	VertexBufferLayout vertex_buffer_layout;
	vertex_buffer_layout.push(4);

	ElementBuffer element_buffer(indices);

	VertexArray vertex_array;
	vertex_array.link_vertex_buffer(vertex_buffer, vertex_buffer_layout);
	vertex_array.link_element_buffer(element_buffer);

	Texture container_texture("assets/textures/jump_king_gold_cap.png");
	container_texture.bind(0);

	Shader vertex_shader("assets/shaders/default.vert");
	Shader fragment_shader("assets/shaders/default.frag");
	Program program(vertex_shader, fragment_shader);

	Matrix4 model = Matrix4::identity();
	model.rotate(Engine::get_time() * Maths::degrees_to_radians(50), Vector3(0, 0, 1));

	program.set_mat4("model", model);

	program.use();
	vertex_array.bind();
	Engine::draw_triangles();
}