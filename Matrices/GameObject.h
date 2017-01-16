#pragma once

#include "Vector2.h"
#include "Vector3.h"

namespace aie {
	class Texture;
	class Renderer2D;
}

class GameObject
{
public:
	GameObject();
	~GameObject();

	void update(float a_dt);
	void draw(aie::Renderer2D* a_spriteBatch);

	void setPosition(const Vector2& a_pos) { m_position = a_pos; }
	void setScale(const Vector2& a_scale) { m_scale = a_scale; }
	void setRoatation(float a_rot) { m_rotation = a_rot; }

	void turnLeft(float a_rot) { m_rotation += a_rot; }

private:
	Vector2 m_position;
	Vector2 m_scale;
	float m_rotation;
	float m_rotationSpeed;
	float m_speed;
	aie::Texture* m_texture;
};

