#include "GameObject.h"
#include "Texture.h"
#include "Renderer2D.h"



GameObject::GameObject()
{
}

GameObject::GameObject(const char * a_szFileName, const Vector2 & a_pos)
{
	m_texture = new aie::Texture(a_szFileName);
	m_position = a_pos;
}


GameObject::~GameObject()
{
	delete m_texture;
}

void GameObject::update(float a_deltaTime)
{

}

void GameObject::draw(aie::Renderer2D* a_spritebatch)
{
	a_spritebatch->drawSprite(m_texture, m_position.x, m_position.y);
}

bool GameObject::isInside(const Vector2& a_pos)
{
	Vector2 delta = m_position - a_pos;
	float distance = delta.magnitude();

	if (distance < m_texture->getWidth()>>1)
	{
		return true;
	}
	return false;
}