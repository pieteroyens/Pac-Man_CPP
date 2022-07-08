#include "GameObject.h"
#include "Globals.h"

#ifndef AGENT_H
#define AGENT_H

class Agent : public GameObject
{
private:
	Agents m_agent_type;
	// Get rid of magic numbers
	float m_movement_speed{ 5.0f };
	bool alive{ true };

public: 
	Agent() : m_agent_type{ Agents::unkown } {};
	Agent(Agents agent_type): m_agent_type{agent_type} {};

	Agents& get_agent_type() { return m_agent_type; };
};

#endif // !AGENT_H




