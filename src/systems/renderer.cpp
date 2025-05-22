#include "renderer.h"

Renderer::Renderer() {
	const std::vector<float> vertices = {
		// Positions  // Texture
		0.0f, 1.0f, 0.0f, 1.0f, // Bottom-left
		0.0f, 0.0f, 0.0f, 0.0f, // Top-left
		1.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
		1.0f, 0.0f, 1.0f, 0.0f  // Top-right
	};

	vertex_buffer = create_unique<VertexBuffer>(vertices);

	VertexBufferLayout vertex_buffer_layout;
	vertex_buffer_layout.push(4);

	const std::vector<int> indices = {
		0, 1, 2, // Bottom-left, top-left, bottom-right
		1, 2, 3  // Top-left, bottom-right, top-right
	};

	element_buffer = create_unique<ElementBuffer>(indices);

	vertex_array = create_unique<VertexArray>();
	vertex_array->link_vertex_buffer(*vertex_buffer, vertex_buffer_layout);
	vertex_array->link_element_buffer(*element_buffer);

	Shader vertex_shader = Shader::from_string_vertex(default_vertex_source);
	Shader fragment_shader = Shader::from_string_fragment(default_fragment_source);
	program = create_unique<Program>(vertex_shader, fragment_shader);
}

void Renderer::add(const Shared<Sprite>& sprite) {
	sprites.push_back(sprite);
}

void Renderer::render(const Window& window, const Camera& camera) {
	Vector2 viewport_size = window.get_viewport_size();

	Matrix4 projection = Matrix4::orthographic(0, viewport_size.width, viewport_size.height, 0, -10000, 10000);
	Matrix4 view = camera._get_matrix(window);

	program->set_mat4("projection", projection);
	program->set_mat4("view", view);

	std::vector<Weak<Sprite>> filtered_sprites;

	for (const Weak<Sprite>& weak_sprite : sprites) {
		// Not thread safe if I later implement multi-threading
		if (weak_sprite.expired()) continue;
		filtered_sprites.push_back(weak_sprite);
		Shared<Sprite> sprite = weak_sprite.lock();

		// Get parent transforms
		std::vector<Shared<Transform>> parents = sprite->transform->_get_parents();

		// Apply parent transformations from root to sprite parent
		Matrix4 model = Matrix4::identity();

		for (int i = parents.size() - 1; i >= 0; i--) {
			Shared<Transform> parent = parents[i];
			model *= parent->_get_matrix();
		}

		// Apply sprite transformation (includes transform and offset)
		model *= sprite->_get_matrix();

		program->set_mat4("model", model);

		// Draw sprite
		sprite->texture->bind(0);
		program->use();
		vertex_array->bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	sprites = filtered_sprites;
}