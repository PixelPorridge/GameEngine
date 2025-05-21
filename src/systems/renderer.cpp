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

	Shader vertex_shader = Shader::from_string_vertex(default_source_vertex);
	Shader fragment_shader = Shader::from_string_fragment(default_source_fragment);
	program = create_unique<Program>(vertex_shader, fragment_shader);
}

void Renderer::add(const Shared<Sprite>& sprite) {
	sprites.push_back(sprite);
}

void Renderer::render(const Window& window, const Camera& camera) {
	Vector2 window_size = window.get_size();

	Matrix4 projection = Matrix4::orthographic(0, window_size.width, window_size.height, 0, -10000, 10000);
	Matrix4 view = Matrix4::identity();

	// Camera offset translations
	Vector2 view_offset = -camera.offset;

	if (camera.centered) {
		view_offset.x += window_size.width / 2;
		view_offset.y += window_size.height / 2;
	}

	view.translate(Vector3(view_offset, 0));

	// Camera transformations
	view.rotate(-camera.rotation, Vector3(0, 0, 1));
	view.scale(Vector3(camera.zoom, 1));
	view.translate(Vector3(-camera.position, 0));

	program->set_mat4("projection", projection);
	program->set_mat4("view", view);

	std::vector<Weak<Sprite>> filtered_sprites;

	for (const Weak<Sprite>& weak_sprite : sprites) {
		// Not thread safe if I later implement multi-threading
		if (weak_sprite.expired()) continue;
		filtered_sprites.push_back(weak_sprite);
		Shared<Sprite> sprite = weak_sprite.lock();

		// Get parent transforms
		std::vector<Shared<Transform>> parents;
		Weak<Transform> weak_parent = sprite->transform->get_parent();

		while (!weak_parent.expired()) {
			Shared<Transform> parent = weak_parent.lock();
			parents.push_back(parent);
			weak_parent = parent->get_parent();
		}

		Matrix4 model = Matrix4::identity();

		// Apply parent transformations from root to sprite parent
		for (int i = parents.size() - 1; i >= 0; i--) {
			Shared<Transform> parent = parents[i];

			model.translate(Vector3(parent->position, 0));
			model.rotate(parent->rotation, Vector3(0, 0, 1));
			model.scale(Vector3(parent->scale, 1));
		}

		// Sprite transformations
		model.translate(Vector3(sprite->transform->position, 0));
		model.rotate(sprite->transform->rotation, Vector3(0, 0, 1));
		model.scale(Vector3(
			sprite->texture->get_width() * sprite->transform->scale.x,
			sprite->texture->get_height() * sprite->transform->scale.y,
			1
		));

		// Sprite offset translations
		Vector2 model_offset(
			sprite->offset.x / sprite->texture->get_width(),
			sprite->offset.y / sprite->texture->get_height()
		);

		if (!sprite->transform->scale.is_any_zero()) {
			model_offset.x /= sprite->transform->scale.x;
			model_offset.y /= sprite->transform->scale.y;
		}

		if (sprite->centered) {
			model_offset -= 0.5f;
		}
		
		model.translate(Vector3(model_offset, 0));

		program->set_mat4("model", model);

		// Draw sprite
		sprite->texture->bind(0);
		program->use();
		vertex_array->bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	sprites = filtered_sprites;
}