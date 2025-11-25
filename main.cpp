#include "ComplexPlane.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <cmath>
#include <iostream>
using namespace std;
using namespace sf;

int main()
{
    int width, height;
    width = VideoMode::getDesktopMode().width;
    height = VideoMode::getDesktopMode().height;
    VideoMode vm(width, height);

    RenderWindow window(vm, "Mandelbrot", Style::Default);

    ComplexPlane plane (width, height);

    Font font;

	if (!font.loadFromFile("batman.ttf"))

	{
		cout << "Error, couldn't open font file" << endl;
	}

	Text text;
	text.setFont(font);
    text.setCharacterSize(24);
	text.setFillColor(Color::White);

    while (window.isOpen())
	{
        Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == Event::Closed)
		    {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
		    {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    plane.zoomIn();
                    plane.setCenter(Vector2f(event.mouseButton.x, event.mouseButton.y));
                }
                else if (event.mouseButton.button == sf::Mouse::Right)
                {
                    plane.zoomOut();
                    plane.setCenter(Vector2f(event.mouseButton.x, event.mouseButton.y));
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                plane.setMouseLocation(Vector2f(event.mouseButton.x, event.mouseButton.y));
            }
            
            if (Keyboard::isKeyPressed(Keyboard::Escape))
		    {
			    window.close();
		    }
    }

    return 0;
}