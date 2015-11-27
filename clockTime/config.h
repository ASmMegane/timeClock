#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <stdio.h> 
#include <Windows.h>
#include "winbase.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h> 

struct gConfig {
	gConfig() {};
	sf::RectangleShape secondArrow;
	sf::RectangleShape minutArrow;
	sf::RectangleShape hourArrow;
	sf::RectangleShape line;
	sf::RenderWindow window;	
	int countLine = 60;
	int radius = 250;
};