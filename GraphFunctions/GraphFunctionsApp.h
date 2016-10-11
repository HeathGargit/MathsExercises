#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Vector2.h"
#include "Texture.h"

class GraphFunctionsApp : public aie::Application {
public:

	GraphFunctionsApp();
	virtual ~GraphFunctionsApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		m_texture;

	Vector2				m_pos;
};