#include "Map.h"
#include "Agent.h"

#ifndef LEVEL_H
#define LEVEL_H

// holds everything that is in a level:
// The map as a grid and all the objects/tiles in it
// The agents present in the level / on the map
class Level
{
private:
	// map (vector of vector of tile objects
	Map m_level_map;
	// in tiles 
	int m_level_height{};
	int m_level_width {};
	// agents array of agents objects
	std::array<Agent, Character_Constants::MAX_AGENTS> m_agents{};

public:
	// function that instantiates the level: get a pre-made level
	Level(Map level_map) : m_level_map{level_map} {};
	Level(Map level_map, std::array<Agent, Character_Constants::MAX_AGENTS> agents)
		: m_level_map{ level_map }, m_agents{ agents } {};
	
	// get the map
	Map& get_level_map() { return m_level_map; };
	std::array<Agent, Character_Constants::MAX_AGENTS>& get_agents() { return m_agents; };
	// update the map: remove pellets and stuff
	// update the actors: move around actours based on AI and player input
	void Update();
};

#endif // !LEVEL_H



