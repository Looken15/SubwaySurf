#include <gl/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "init.h"
#include "release.h"
#include "draw.h"

int main() {
	sf::Window window(sf::VideoMode(700, 700), "Subway Surf", sf::Style::Default, sf::ContextSettings(24));
	window.setVerticalSyncEnabled(true);
	window.setActive(true);

	// Инициализация glew
	glewInit();
	glEnable(GL_DEPTH_TEST);

	Init();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::Resized) {
				glViewport(0, 0, event.size.width, event.size.height);
			}
			else if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case (sf::Keyboard::A):
				{
					busMove[0] -= 0.1;
					busRotate[1] -= 0.1;
					break;
				}
				case (sf::Keyboard::D):
				{
					busMove[0] += 0.1;
					busRotate[1] += 0.1;
					break;
				}
				default: break;
				}
			}
		}

		if (busRotate[1] < -3.14f && std::abs(busRotate[1] + 3.14) > 0.1f)
			busRotate[1] += 0.03f;
		else if (busRotate[1] > -3.14f && std::abs(busRotate[1] + 3.14) > 0.1f)
			busRotate[1] -= 0.03f;
		if (std::abs(busMove[1] + 0.25) < 0.01f)
			busMove[1] += 1.0f;

		road1Move[2] -= 0.05;
		road2Move[2] -= 0.05;
		road3Move[2] -= 0.05;
		if (std::abs(road1Move[2] + 10) < 0.001)
			road1Move[2] = 10;
		if (std::abs(road2Move[2] - 10) < 0.001)
			road2Move[2] = 30;
		if (std::abs(road3Move[2] - 30) < 0.001)
			road3Move[2] = 50;


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Draw();

		window.display();
	}

	Release();
	return 0;
}

