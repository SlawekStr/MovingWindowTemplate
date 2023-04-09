#include "MovingWindow.h"
#include "src/Utility/Timer.h"
#include <iostream>

////////////////////////////////////////////////////////////
MovingWindow::MovingWindow(unsigned windowWidth, unsigned windowHeight, std::string windowTitle, unsigned framerate) 
	: Window{windowWidth,windowHeight,windowTitle,framerate}, m_camera{ m_window }
{
}

////////////////////////////////////////////////////////////
void MovingWindow::run()
{
	Timer t;
	while (m_window.isOpen())
	{
		t.start();
		pollEvent();
		update();
		m_window.clear(sf::Color(128, 128, 128));
		draw();
		m_window.display();
		t.stop();
		std::cout << "Frame time: " << t.measure() << std::endl;
	}
}

////////////////////////////////////////////////////////////
void MovingWindow::pollEvent()
{
	sf::Event e;
	while (m_window.pollEvent(e))
	{
		if (m_camera.handleEvent(e))
		{
			break;
		}
		switch (e.type)
		{
			case sf::Event::Closed:
			{
				m_window.close();
				break;
			}
			case sf::Event::KeyPressed:
			{
				if (e.key.code == sf::Keyboard::Escape)
				{
					m_window.close();
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////
void MovingWindow::update()
{
}

////////////////////////////////////////////////////////////
void MovingWindow::draw()
{
	sf::RectangleShape rectangle(sf::Vector2f(1920.0f, 1080.0f));
	rectangle.setFillColor(sf::Color::White);
	m_window.draw(rectangle);
}
