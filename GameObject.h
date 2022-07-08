#include "Globals.h"

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
/*
	Base Class of all visible and invisble objects in the game.
	This includes the player and everything they can interact with.
*/
class GameObject
{
// public for now, fix access later
private: 
	Position m_position{ };

public:
	GameObject() : m_position{ 0.0, 0.0 } {};
	
	void setPosition(float x, float y)
	{
		m_position.x = x;
		m_position.y = y;
	}

	void updatePosition(float x, float y)
	{
		m_position.x += x;
		m_position.y += y;
	}

	Position& getPosition ()
	{
		return m_position;
	}

};

#endif // !GAME_OBJECT_H




