//Level.cpp
#include <fstream>
#include <Windows.h>
#include "Level.h"

using namespace std;

Level::Level(void)
{
}


Level::~Level(void)
{
}


bool Level::loadFromFile(std::string filename)
{
	fstream file("data/levels/"+filename,ios::in);
	if(!file.is_open())
	{
		MessageBox(NULL,filename.c_str(),"Cannot find the file!",NULL);
		return false;
	}
	
	int tmp;

	file >> tmp >> tmp;
	
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			int tmp;
			file >> tmp;

			m_data[i][j].type = FieldType(tmp);
			if(tmp == 0)
				m_data[i][j].isWall = false;
			else
				m_data[i][j].isWall = true;
		}
	}

	file.close();
	return true;
}