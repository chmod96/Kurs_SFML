//Player.h
#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class Player: public sf::Drawable,
	sf::Transformable
{
public:
	Player(void);
	~Player(void);

	enum Status {
	GO_DWN,GO_LEFT_DWN,GO_LEFT,GO_UP_LEFT,
	GO_UP,GO_UP_RIGHT,GO_RIGHT,GO_DOWN_RIGHT,
	Status_Count};

	sf::Vector2f getPos();
	Status getStatus();

	void update();
	void playAnimation(bool play);

	void goDown();
	void goUp();

	void goLeft();
	void goRight();

	void stopVertical();
	void stopHorizontal();

protected:
	int frame;
	std::vector<int> frame_count;

private:
	sf::Sprite sprite;
	sf::Texture texture;

	Status status;
	bool animation;

	float speed;

	//prêdkoœæ poruszania siê gracza
	float vx; //w poziomie
	float vy; //w pionie
	
	virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};