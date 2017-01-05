#include "TrigonometryApp.h"
#include "Font.h"
#include "Input.h"
#include "Utility.h"
#include "Texture.h"
#include "GameObject.h"

TrigonometryApp::TrigonometryApp() {

}

TrigonometryApp::~TrigonometryApp() {

}

bool TrigonometryApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_player = new GameObject("./textures/ship.png");
	m_player->m_position = Vector2(this->getWindowWidth() >> 1, this->getWindowHeight() >> 1);
	m_player->m_rotation = degToRad(30);

	m_enemy = new GameObject("./textures/rock_large.png");
	m_enemy->m_position = Vector2(this->getWindowWidth() - 400, this->getWindowHeight() - 100);
	m_enemy->m_rotation = 0;

	return true;
}

void TrigonometryApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void TrigonometryApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	Vector2 dir = Vector2(m_enemy->m_position - m_player->m_position);
	float rads = atan2f(dir.y, dir.x);
	m_player->m_rotation = rads;
	
	m_string = cosrule_angle(8.0f, 6.0f, 9.0f);
}

void TrigonometryApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_player->draw(m_2dRenderer);
	m_enemy->draw(m_2dRenderer);

	Vector2 direction(cosf(m_player->m_rotation), sinf(m_player->m_rotation));
	m_2dRenderer->drawLine(m_player->m_position.x, m_player->m_position.y, m_player->m_position.x + direction.x * 200, m_player->m_position.y + direction.y * 200);


	// output some text
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	m_2dRenderer->drawText(m_font, m_string.c_str(), 0, 100);

	// done drawing sprites
	m_2dRenderer->end();
}

std::string TrigonometryApp::cosrule_angle(const float side_a, const float side_b, const float side_c)
{
	float angle_a, angle_b, angle_c;
	float sum = 0;
	std::string returnThis;
	angle_a = radToDeg(acos((Quadratic(side_b) + Quadratic(side_c) - Quadratic(side_a)) / (2 * side_b * side_c)));
	angle_b = radToDeg(acos((Quadratic(side_a) + Quadratic(side_c) - Quadratic(side_b)) / (2 * side_a * side_c)));
	angle_c = radToDeg(acos((Quadratic(side_b) + Quadratic(side_a) - Quadratic(side_c)) / (2 * side_b * side_a)));
	sum = angle_a + angle_b + angle_c;

	returnThis = "A: " + std::to_string(angle_a) + ". B: " + std::to_string(angle_b) + ". C: " + std::to_string(angle_c) + ". Sum of these angles: " + std::to_string(sum) + ".";
	return returnThis;
}
