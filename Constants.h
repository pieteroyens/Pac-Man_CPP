#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Map_Constants
{
	constexpr int MAP_HEIGHT{ 5 }; // number of rows
	constexpr int MAP_WIDTH{ 11 }; // number of columns
	
	constexpr int TILE_SIZE{ 32 }; // size in pixels of each tile on the map;
}

namespace Character_Constants
{
	constexpr int MAX_GHOSTS{ 3 };
	constexpr int MAX_AGENTS{ MAX_GHOSTS + 1 }; // all ghosts + pacman
	constexpr float PAC_MAN_SPEED{ 5.0f };
	constexpr float GHOSTS_SPEED{ 5.0f };
}

#endif // !CONSTANTS_H

