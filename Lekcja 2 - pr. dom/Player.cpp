//Player.cpp
#include "Player.h"
#include <Windows.h>

using namespace sf;

Player::Player(void)
{
	if(!texture.loadFromFile("data/images/mechwarrior.png"))
	{
		MessageBox(NULL,"Textures not found!","ERROR",NULL);
		return;
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0,0,80,80));
	
	status = GO_DWN;
	int size[Status_Count] = {10,16,9,15,10,15,9,16};
	for(int i=0;i<Status_Count;i++)
		frame_count.push_back(size[i]);

	frame = 0;
	speed = 1.5;

	vx = 0;
	vy = 0;
	
	animation = false;

}


Player::~Player(void)
{
}


sf::Vector2f Player::getPos()
{
	return sprite.getPosition();
}


Player::Status Player::getStatus()
{
	return status;
}


void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprite);
}


void Player::update()
{
	//sprawdzamy czy postaæ siê porusza
	if(vx == 0 && vy == 0)
		playAnimation(false);
	else
	{
		//postaæ idzie w dó³
		if(vx == 0 && vy > 0)
			status = GO_DWN;
		//postaæ idzie w góre
		else if(vx ==0 && vy < 0)
			status = GO_UP;
		//postac idzie w prawo
		else if(vx > 0 && vy == 0)
			status = GO_RIGHT;
		//postac idzie w lewo
		else if(vx < 0 && vy == 0)
			status = GO_LEFT;
		//lewo-dó³
		else if(vx < 0 && vy > 0)
			status = GO_LEFT_DWN;
		//lewo-góra
		else if(vx < 0 && vy < 0)
			status = GO_UP_LEFT;
		//prawo-dó³
		else if(vx > 0 && vy > 0)
			status = GO_DOWN_RIGHT;
		//prawo-góra
		else if(vx > 0 && vy < 0)
			status = GO_UP_RIGHT;

		playAnimation(true);
	}

	if(animation)
	{
		if(frame < frame_count[status])
			frame++;
		else
			frame = 0;
		
		sprite.setTextureRect(IntRect(status*87,frame*80,87,80));
	}

	sprite.move(vx,vy);
}


void Player::playAnimation(bool play)
{
	animation = play;

	if(animation == false)
	{
		frame = 0;
		sprite.setTextureRect(IntRect(status*87,frame*80,87,80));
	}
}


void Player::goDown()
{
	vy = speed;
}


void Player::goUp()
{
	vy = -speed;
}


void Player::goLeft()
{
	vx = -speed;
}


void Player::goRight()
{
	vx = speed;
}


void Player::stopHorizontal()
{
	vx = 0;
	frame = 0;
}


void Player::stopVertical()
{
	vy = 0;
	frame = 0;
}