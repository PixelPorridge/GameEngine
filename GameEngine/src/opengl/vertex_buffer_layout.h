#pragma once

#include <glad/glad.h>
#include <vector>

struct VertexBufferAttribute {
	GLint size;
	GLenum type;
	GLboolean normalised;
	GLuint offset;
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferAttribute> attributes;
	GLsizei stride = 0;

public:
	template<typename T>
	void push(GLint size);

	template<>
	void push<GLfloat>(GLint size) {
		attributes.push_back({size, GL_FLOAT, GL_FALSE, (GLuint)stride});
		stride += size * sizeof(GLfloat);
	}

	template<>
	void push<GLuint>(GLint size) {
		attributes.push_back({size, GL_UNSIGNED_INT, GL_FALSE, (GLuint)stride});
		stride += size * sizeof(GLuint);
	}

	template<>
	void push<GLubyte>(GLint size) {
		attributes.push_back({size, GL_UNSIGNED_BYTE, GL_FALSE, (GLuint)stride});
		stride += size * sizeof(GLubyte);
	}

	inline const std::vector<VertexBufferAttribute>& get_attributes() const {
		return attributes;
	}

	inline const GLsizei get_stride() const {
		return stride;
	}
};