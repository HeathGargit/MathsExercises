#include "GraphFunctionsApp.h"
#include "Font.h"
#include "Input.h"
#include "Utility.h"
#include <math.h>

GraphFunctionsApp::GraphFunctionsApp() {

}

GraphFunctionsApp::~GraphFunctionsApp() {

}

bool GraphFunctionsApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_texture = new aie::Texture("./textures/rock_small.png");
	m_pos = Vector2(0, 100);

	return true;
}

void GraphFunctionsApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void GraphFunctionsApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	static float t0 = 0;
	t0 += deltaTime;
	if (t0 >= 5)
		t0 = 0;
	static float t1 = 0;
	t1 += deltaTime;
	
	float tx = t0/5;
	float ty = t1;

	//m_pos.x = LinearHalf(t * getWindowWidth());

	//1a
	//m_pos.x = Quadratic(t * sqrt(getWindowWidth())); 
	
	//1b
	//pos.x = getWindowWidth() - (Quadratic((1 - t) * sqrt(getWindowWidth())));

	//1c
	/*m_pos.x = tx * getWindowWidth();
	m_pos.y = (LinearHalf(Sine(ty)) * getWindowHeight()) + (getWindowHeight() / 2);*/

	//1d
	/*m_pos.x = tx * getWindowWidth();
	m_pos.y = GetUnAbsolute(((Sine((1 - ty) * 3) * getWindowHeight()) * (1-tx))) + (getWindowHeight());*/

	//1e
	float offset = LinearHalf(getWindowWidth());
	m_pos.x = tx * getWindowWidth();
	m_pos.y = getWindowHeight() - (Quadratic(tx*2) * getWindowHeight());

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void GraphFunctionsApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_2dRenderer->drawSprite(m_texture, m_pos.x, m_pos.y);

	// output some text
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}