//Engine.h
#pragma once

#include <queue>

#include "Player.h"
#include "Level.h"
#include "BulletsSystem.h"

class Engine
{
public:
	Engine(sf::RenderWindow &win);
	~Engine(void);

	void runEngine();

private:
	sf::RenderWindow *window;
	
	Player player;
	Level level;

	BulletsSystem bullets;

	sf::Texture t_tile[Level::COUNT];
	sf::Sprite map[Level::height][Level::width];

	void update();
	void draw();

	bool playerCanShoot(Vector2f mouse);
};

