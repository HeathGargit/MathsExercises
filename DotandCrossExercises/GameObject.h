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
	GameObject(const char* a_szFileName, const Vector2& a_pos);
	~GameObject();

	void update(float a_deltaTime);
	void draw(aie::Renderer2D* a_spritebatch);

	inline void setPosition(const Vector2& a_pos) { m_position = a_pos; }
	inline Vector2 getPosition() { return m_position; }

	bool isInside(const Vector2& a_pos);

protected:
	Vector2 m_position;
	aie::Texture* m_texture;
};

