#include "Engine.h"
using namespace sf;

Engine::Engine(sf::RenderWindow &win)
{
	window = &win;
}


Engine::~Engine(void)
{
}

void Engine::runEngine()
{
	bool menu = false;

	sf::Clock zegar;
	
	while(!menu)
	{
		Event event;
		while(window->pollEvent(event))
		{
			if(event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
				menu = true;
			
			if(event.type == Event::KeyPressed && event.key.code == Keyboard::W)
			{
				player.goUp();
			}
			
			if(event.type == Event::KeyPressed && event.key.code == Keyboard::S)
			{
				player.goDown();
			}

			if(event.type == Event::KeyPressed && event.key.code == Keyboard::A)
			{
				player.goLeft();
			}

			if(event.type == Event::KeyPressed && event.key.code == Keyboard::D)
			{
				player.goRight();
			}
			
			else if(event.type == Event::KeyReleased)
			{
				if(event.key.code == Keyboard::W || event.key.code == Keyboard::S)
					player.stopVertical();
				if(event.key.code == Keyboard::A || event.key.code == Keyboard::D)
					player.stopHorizontal();
			}
		}
		
		if(zegar.getElapsedTime() > sf::seconds(0.1))
		{
			player.update();
			zegar.restart();
		}
		
		window->clear();
		window->draw(player);
		window->display();
	}
}