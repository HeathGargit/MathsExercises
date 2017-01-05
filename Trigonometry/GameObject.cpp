#include "GameObject.h"
#include "Texture.h"
#include "Renderer2D.h"


GameObject::GameObject()
{
}

GameObject::GameObject(const char* sz_filename)
{
	m_Sprite = new aie::Texture(sz_filename);
}


GameObject::~GameObject()
{
	delete m_Sprite;
}

void GameObject::draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(m_Sprite, m_position.x, m_position.y, 0, 0, m_rotation);
}
