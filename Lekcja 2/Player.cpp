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
	
	animation = false;

}


Player::~Player(void)
{
}


void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprite);
}


void Player::update()
{
	if(animation)
	{
		if(frame < frame_count[status])
			frame++;
		else
			frame = 0;
		
		sprite.setTextureRect(IntRect(status*87,frame*80,87,80));
	}
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
	status = GO_DWN;
	sprite.move(0,speed);

	playAnimation(true);
}


void Player::goUp()
{
	status = GO_UP;
	sprite.move(0,-speed);

	playAnimation(true);
}


void Player::goLeft()
{
	status = GO_LEFT;
	sprite.move(-speed,0);

	playAnimation(true);
}


void Player::goRight()
{
	status = GO_RIGHT;
	sprite.move(speed,0);

	playAnimation(true);
}


void Player::stop()
{
	playAnimation(false);
}