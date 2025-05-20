#include "sprite.h"

Sprite::Sprite(const std::string& path) {
	transform = create_shared<Transform>();
	texture = create_unique<Texture>(path);
}