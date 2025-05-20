#include "sprite.h"

Sprite::Sprite(const std::string& path) {
	texture = create_unique<Texture>(path);
}