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
			update();
			zegar.restart();
		}

		draw();
	}
}


void Engine::update()
{
	Vector2f speed = player.getVelocity();
	Vector2f pos = player.getPos();
	
	int mx,my;
	if(speed.x > 0) mx = -1;
	else mx = 1;

	if(speed.y > 0) my = -1;
	else my = 1;

	for(int i=0;i<=player.width;i++)
	{
		for(int j=0;j<=player.height;j++)
		{
			int nextX = (player.getNextPosition().x+i)/40;
			int nextY = (player.getNextPosition().y+j)/40;
			
			if(level.m_data[nextY][nextX].isWall)
			{
				if(speed.x != 0)
					speed.x += mx;
				if(speed.y != 0)
					speed.y += my;
				player.setVelocity(speed.x,speed.y);
			}
		}
	}
	player.update();
}


void Engine::draw()
{
	window->clear();
		
	for(int i=0;i<level.getHeight();i++)
		for(int j=0;j<level.getWidth();j++)
			window->draw(map[i][j]);

	window->draw(player);
		
	window->display();
}