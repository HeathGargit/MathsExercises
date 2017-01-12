#include "DotandCrossExercisesApp.h"
#include "Font.h"
#include "Input.h"
#include "Vector2.h"
#include "Vector3.h"
#include "GameObject.h"
#include "imgui.h"
#include "Utility.h"
#include "Matrix3.h"

DotandCrossExercisesApp::DotandCrossExercisesApp() {

}

DotandCrossExercisesApp::~DotandCrossExercisesApp() {

}

bool DotandCrossExercisesApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_answer = "";

	m_obj1 = new GameObject("./textures/ship.png", Vector2(400, 400));
	m_obj2 = new GameObject("./textures/ship.png", Vector2(900, 600));

	return true;
}

void DotandCrossExercisesApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void DotandCrossExercisesApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	/*Vector3 vecA(0.45, 0.2, -0.69), vecB(0, 1.0, 0), vecC(0, 0, 0);
	vecC = vecA.cross(vecB);
	Vector2 vecA(-1, -1), vecB(-5, -6);
	vecA.normalize();
	vecB.normalize();
	float answer = vecA.dot(vecB);
	answer = radToDeg(acos(answer));
	m_answer = vecC.to_string();*/

	static bool mouseDown = false;

	int x, y;
	input->getMouseXY(&x, &y);
	Vector2 mouse(x, y);

	if (input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
	{
		mouseDown = true;
	}
	if (input->wasMouseButtonReleased(aie::INPUT_MOUSE_BUTTON_LEFT))
	{
		mouseDown = false;
	}
	if (mouseDown == true)
	{
		if (m_obj1->isInside(mouse))
		{
			m_obj1->setPosition(mouse);
		}

	}
	
	Vector2 centre(getWindowWidth() >> 1, getWindowHeight() >> 1);

	Vector2 ob1 = m_obj1->getPosition() - centre;
	Vector2 ob2 = m_obj2->getPosition() - centre;

	ob1.normalise();
	ob2.normalise();

	float dot = ob1.dot(ob2);
	float angle = radToDeg(acosf(dot));

	ImGui::Text("Angle: %.2f", angle);

	Vector2 perp(ob1.y, -ob1.x);
	float perpdot = perp.dot(ob2);

	if (perpdot < 0)
	{
		angle = 360 - angle;
	}

	ImGui::Text("Corrected Angle: %.2f", angle);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void DotandCrossExercisesApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	Vector2 centre(getWindowWidth() >> 1, getWindowHeight() >> 1);
	m_2dRenderer->drawLine(centre.x, centre.y, m_obj1->getPosition().x, m_obj1->getPosition().y);
	m_2dRenderer->drawLine(centre.x, centre.y, m_obj2->getPosition().x, m_obj2->getPosition().y);

	// draw your stuff here!
	//m_2dRenderer->drawText(m_font, m_answer.c_str(), 10, 100);
	m_obj1->draw(m_2dRenderer);
	m_obj2->draw(m_2dRenderer);

	// output some text
	//m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}