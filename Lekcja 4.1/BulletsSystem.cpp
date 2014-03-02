//BulletsSystem.cpp
#include "BulletsSystem.h"


BulletsSystem::BulletsSystem(void)
{
	m_speed = 11;
}


BulletsSystem::BulletsSystem(float delta)
{
	m_speed = 11;
	m_delta=delta;
}


BulletsSystem::~BulletsSystem(void)
{
}


void BulletsSystem::addBullet(Vector2f emitter, Vector2f target)
{
	Bullet tmp;
		
	_Vector2 direction = _Vector2(target.x,target.y)-_Vector2(emitter.x,emitter.y);
	direction.normalize();

	tmp.velocity = Vector2f(direction.x*m_speed,direction.y*m_speed);
		
	tmp.vert.position = emitter;
	tmp.lifetime = 75;

	m_bullets.push_back(tmp);
}


void BulletsSystem::update()
{	
	for(int i=0;i<m_bullets.size();i++)
	{
		m_bullets[i].vert.position += m_bullets[i].velocity;
		m_bullets[i].lifetime--;
	}
		
	for(int i=0;i<m_bullets.size();i++)
	{
		Vector2f poz = m_bullets[i].vert.position;
			
		if(poz.x < 0 || poz.x > 1280 || poz.y < 0 || poz.y > 720
			|| m_bullets[i].lifetime <= 0)
		{
			for(int j=i;j<m_bullets.size()-1;j++)
			{
				Bullet tmp = m_bullets[j];
				m_bullets[j] = m_bullets[j+1];

				m_bullets[j+1] = tmp;
			}
			m_bullets.pop_back();
		}
	}	
}


void BulletsSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = NULL;

	for(int i=0;i<m_bullets.size();i++)
	{
		target.draw(&m_bullets[i].vert,1,PrimitiveType::Points);
	}
}