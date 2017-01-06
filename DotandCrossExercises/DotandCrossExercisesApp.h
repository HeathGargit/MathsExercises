#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <string>
#include "Utility.h"

class GameObject;

class DotandCrossExercisesApp : public aie::Application {
public:

	DotandCrossExercisesApp();
	virtual ~DotandCrossExercisesApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	std::string			m_answer;

	GameObject*			m_obj1;
	GameObject*			m_obj2;

};