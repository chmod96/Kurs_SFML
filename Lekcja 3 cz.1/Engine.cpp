//Engine.cpp
#include "Engine.h"
#include <Windows.h>

using namespace sf;

Engine::Engine(sf::RenderWindow &win)
{
	window = &win;

	if(!level.loadFromFile("map.level"))
		return;

	for(int i=0;i<Level::COUNT;i++)
	{
		if(!t_tile[i].loadFromFile("data/images/tiles.png",IntRect(i*40,0,40,40)))
		{
			MessageBox(NULL,"tiles.png","Textures not found!",NULL);
			return;
		}
	}

	for(int i=0;i<level.getHeight();i++)
	{
		for(int j=0;j<level.getWidth();j++)
		{
			map[i][j].setTexture(t_tile[level.m_data[i][j].type]);
			map[i][j].setPosition(j*40,i*40);
		}
	}
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
		
		for(int i=0;i<level.getHeight();i++)
			for(int j=0;j<level.getWidth();j++)
				window->draw(map[i][j]);

		window->draw(player);
		
		window->display();
	}
}