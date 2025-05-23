#include "texture.h"

#include "glad/glad.h"
#include "stb/stb_image.h"

/*
*	Texture
* 
*	A texture is used to supply an image to the render pipeline.
*	They can be loaded using stb_image and the image file path.
*	Textures need to be bound to a texture unit so that the fragment shader can find it.
*/

Texture::Texture(const std::string& path) {
	int channels;
	unsigned char* pixels = stbi_load(path.c_str(), &width, &height, &channels, 0);

	if (pixels == nullptr) {
		Debug::log("Failed to load texture image: " + path, Debug::ERROR);
		stbi_image_free(pixels);
		return;
	}

	glCreateTextures(GL_TEXTURE_2D, 1, &id);

	switch (channels) {
	case 3:
		glTextureStorage2D(id, 1, GL_RGB8, width, height);
		glTextureSubImage2D(id, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
		break;
	case 4:
		glTextureStorage2D(id, 1, GL_RGBA8, width, height);
		glTextureSubImage2D(id, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
		break;
	}

	glGenerateTextureMipmap(id);

	stbi_image_free(pixels);
}

Texture::~Texture() {
	glDeleteTextures(1, &id);
}

unsigned int Texture::get_id() const {
	return id;
}

int Texture::get_width() const {
	return width;
}

int Texture::get_height() const {
	return height;
}

void Texture::bind(int unit) const {
	glBindTextureUnit(unit, id);
}