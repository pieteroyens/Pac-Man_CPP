#include <iostream>
#include <vector>
#include <string>
#include <string_view>

#include "Map.h"
#include "Constants.h"
#include "Utility.h"
#include "TileObject.h"
#include "Globals.h"
#include "LevelFactory.h"
#include "Level.h"

/* 
Responsible for reading in a text file that reprents a starting level of pacman
It should return the level map and all the agents (Pac-Man and the ghosts).
*/

Level generate_level(const std::string& level_file)
{
	std::cout << "Reading the level from file: " << level_file << '\n';
	std::vector<std::string> raw_map{ read_level(level_file) };
	
	auto rows    { raw_map.size() };
	auto columns { raw_map[0].size() };

	// We use a vector since we want to be able to load in maps of variable size
	// and do not use array since we need to size to be const for the compiler.
	std::vector<std::vector<TileObject>> tile_grid;

	// The max amount of agents in a level (ghosts + Pac-Man)
	std::array<Agent, Character_Constants::MAX_AGENTS> agents {};
	int ghosts_seen{ 0 };

	// Read in all tiles and agents from the level file
	for (int row = 0; row < rows - 1; ++row)
	{
		std::vector<TileObject> row_vector{};

		for (int column = 0; column < columns; ++column)
		{
			// basic tile is empty
			TileObject tile = TileObject();

			// improve the code to setup the location of the agents and the tiles
			if (Agents(raw_map[row][column]) == Agents::pacman)
			{
				agents[0] = Agent(Agents::pacman);
				agents[0].setPosition(column * Map_Constants::TILE_SIZE,
					row * Map_Constants::TILE_SIZE);
			}
			else if (Agents(raw_map[row][column]) == Agents::ghost)
			{
				agents[ghosts_seen + 1] = Agent(Agents::ghost);
				agents[ghosts_seen + 1].setPosition(column * Map_Constants::TILE_SIZE,
					row * Map_Constants::TILE_SIZE);
				++ghosts_seen;
			}
			else
				tile.setTileType(Tiles(raw_map[row][column]));

			tile.setPosition(column * Map_Constants::TILE_SIZE,
				row * Map_Constants::TILE_SIZE);
			row_vector.push_back(tile);
		}

		// add row to the tile grid
		tile_grid.push_back(row_vector);
	}

	// Instantiate a level
	Level level(tile_grid, agents);
	return level;
}