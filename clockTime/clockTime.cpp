#include "stdafx.h"
#include "config.h"

void createArrow(gConfig & conf) {
	conf.secondArrow.setSize(sf::Vector2f(200, 5));
	conf.secondArrow.setOrigin(0, conf.secondArrow.getSize().y / 2);
	conf.secondArrow.setPosition((float)conf.window.getSize().x / 2, (float)conf.window.getSize().y / 2);
	conf.secondArrow.setFillColor(sf::Color(100, 250, 50));
	
	conf.minutArrow.setSize(sf::Vector2f(150, 7));
	conf.minutArrow.setOrigin(0, conf.minutArrow.getSize().y / 2);
	conf.minutArrow.setPosition((float)conf.window.getSize().x / 2, (float)conf.window.getSize().y / 2);
	conf.minutArrow.setFillColor(sf::Color(70, 130, 180));

	conf.hourArrow.setSize(sf::Vector2f(100, 9));
	conf.hourArrow.setOrigin(0, conf.hourArrow.getSize().y / 2);
	conf.hourArrow.setPosition((float)conf.window.getSize().x / 2, (float)conf.window.getSize().y / 2);
	conf.hourArrow.setFillColor(sf::Color(255, 69, 0));
}
void drawingObjeckt(gConfig & conf) {
	conf.window.clear(sf::Color(255, 255, 255));
	for (int i = 0; i < conf.countLine; i++) {
		conf.line.setPosition((float)(conf.window.getSize().x / 2 + (conf.radius * cos(6 * i * M_PI / 180))), (float)(conf.window.getSize().y / 2 + (conf.radius * sin(6 * i * M_PI / 180))));
		conf.line.setRotation(float(90 + (6 * i)));
		if ((i % 5) == 0) {
			conf.line.setScale(1, 3);
		}
		if (i % 15 == 0) {
			conf.line.setScale(2, 3);
		}
		conf.window.draw(conf.line);
		conf.line.setScale(1, 1);
	}
	conf.window.draw(conf.hourArrow);
	conf.window.draw(conf.minutArrow);
	conf.window.draw(conf.secondArrow);
	conf.window.display();
}

void clockTime(gConfig & conf) {	
	SYSTEMTIME systime;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 6;
	conf.window.create(sf::VideoMode(800, 600), "Clock", sf::Style::Default, settings);

	createArrow(conf);
	conf.line.setSize(sf::Vector2f(2.0, 10.0));
	conf.line.setFillColor(sf::Color(0, 0, 0));
	while (conf.window.isOpen()) {
		GetLocalTime(&systime);
		sf::Event event;
		while (conf.window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				conf.window.close();
		}
		conf.secondArrow.setRotation((float)systime.wSecond * 6 - 90);
		conf.minutArrow.setRotation((float)systime.wMinute * 6 - 90);
		conf.hourArrow.setRotation((float)systime.wHour * 30 - 90);
		drawingObjeckt(conf);
		sf::sleep(sf::milliseconds(1000 - systime.wMilliseconds));
	}
}

int main()
{
	gConfig conf;
	clockTime(conf);
    return 0;
}

