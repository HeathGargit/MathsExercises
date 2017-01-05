#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <string>

class GameObject;

class TrigonometryApp : public aie::Application {
public:

	TrigonometryApp();
	virtual ~TrigonometryApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	std::string cosrule_angle(const float side_a, const float side_b, const float side_c);

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	std::string			m_string;
	GameObject*			m_player;
	GameObject*			m_enemy;
};