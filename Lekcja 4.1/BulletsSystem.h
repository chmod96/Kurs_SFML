//BulletsSystem.h
#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "_Vector2.h"

using namespace sf;
using namespace std;

class BulletsSystem:public Drawable
{
public:
	BulletsSystem(void);
	BulletsSystem(float delta_time);

	~BulletsSystem(void);

	void addBullet(Vector2f emitter,Vector2f target);
	void update();

	void setDelta(float d){m_delta=d;}

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	struct Bullet
	{
		Vertex vert;
		Vector2f velocity;
		int lifetime;
	};

	vector <Bullet> m_bullets;
	
	float m_speed;
	float m_delta;
};