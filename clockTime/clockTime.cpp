#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <stdio.h> 
#include <Windows.h>
#include "winbase.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h> 



void clockTime() {
	SYSTEMTIME systime;
	sf::RenderWindow window;
	sf::ContextSettings settings;
	int countLine = 60;
	int radius = 250;
	settings.antialiasingLevel = 6;
	window.create(sf::VideoMode(800, 600), "Clock", sf::Style::Default, settings);
	std::string addresClock = "image/clockImg.png";

	sf::RectangleShape secondArrow(sf::Vector2f(200, 5));
	secondArrow.setOrigin(0, secondArrow.getSize().y / 2);
	secondArrow.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2);
	secondArrow.setFillColor(sf::Color(100, 250, 50));

	sf::RectangleShape minutArrow(sf::Vector2f(150, 7));
	minutArrow.setOrigin(0, minutArrow.getSize().y / 2);
	minutArrow.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2);
	minutArrow.setFillColor(sf::Color(70, 130, 180));

	sf::RectangleShape hourArrow(sf::Vector2f(100, 9));
	hourArrow.setOrigin(0, hourArrow.getSize().y / 2);
	hourArrow.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2);
	hourArrow.setFillColor(sf::Color(255, 69, 0));

	sf::RectangleShape line(sf::Vector2f(2.0, 10.0));
	line.setFillColor(sf::Color(0, 0, 0));


	while (window.isOpen()) {
		GetLocalTime(&systime);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		secondArrow.setRotation((float)systime.wSecond * 6 - 90);
		minutArrow.setRotation((float)systime.wMinute * 6 - 90);
		hourArrow.setRotation((float)systime.wHour * 30 - 90);
		window.clear(sf::Color(255, 255, 255));
		for (int i = 0; i < countLine; i++) {
			line.setPosition((float)(window.getSize().x / 2 + (radius * cos(6 * i * M_PI / 180))), (float)(window.getSize().y / 2 + (radius * sin(6 * i * M_PI / 180))));
			line.setRotation(float(90 + (6 * i)));
			if ((i % 5) == 0) {
				line.setScale(1, 3);
			}
			if (i % 15 == 0) {
				line.setScale(2, 3);
			}
			window.draw(line);
			line.setScale(1, 1);
		}
		window.draw(hourArrow);
		window.draw(minutArrow);
		window.draw(secondArrow);
		window.display();
		sf::sleep(sf::milliseconds(1000 - systime.wMilliseconds));
	}

}

int main()
{
	clockTime();
    return 0;
}

