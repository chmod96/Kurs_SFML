//Level.h
#pragma once

#include <string>

class Level
{
public:
	Level(void);
	~Level(void);

	enum FieldType
	{
		FIELD_FLOOR,
		FIELD_WALL,

		COUNT
	};

	struct Data
	{
		FieldType type;
		bool isWall;
	};

	static const int width = 32;
	static const int height = 18;
	
	Data m_data[height][width];

	bool loadFromFile(std::string filename);
	
	int getWidth() {return width;}
	int getHeight() {return height;}
};