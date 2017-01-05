#include "DotandCrossExercisesApp.h"
#include "Font.h"
#include "Input.h"
#include "Vector2.h"
#include "Vector3.h"

DotandCrossExercisesApp::DotandCrossExercisesApp() {

}

DotandCrossExercisesApp::~DotandCrossExercisesApp() {

}

bool DotandCrossExercisesApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_answer = "";

	return true;
}

void DotandCrossExercisesApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void DotandCrossExercisesApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	Vector3 vecA(0.45, 0.2, -0.69), vecB(0, 1.0, 0), vecC(0, 0, 0);
	vecC = vecA.cross(vecB);
	/*Vector2 vecA(-1, -1), vecB(-5, -6);
	vecA.normalize();
	vecB.normalize();
	float answer = vecA.dot(vecB);
	answer = radToDeg(acos(answer));*/


	m_answer = vecC.to_string();


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void DotandCrossExercisesApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_2dRenderer->drawText(m_font, m_answer.c_str(), 10, 100);

	// output some text
	//m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}