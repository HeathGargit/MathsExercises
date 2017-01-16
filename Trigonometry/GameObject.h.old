#pragma once

#include "Vector2.h"

namespace aie {
	class Texture;
	class Renderer2D;
}

class GameObject
{
public:
	GameObject();
	GameObject(const char* sz_filename);
	~GameObject();

	void draw(aie::Renderer2D* renderer);

	aie::Texture* m_Sprite;
	Vector2 m_position;
	float m_rotation;
};

