#ifndef GLOBALS_H
#define GLOBALS_H

// Static objects and their identifier.
enum class Tiles
{
	wall         = '*',
	empty        = ' ',
	pellet       = '.',
	super_pellet = '+',
	teleport     = '1', // find a nicer way to get a teleport location
};

// Either the player or a ghost and their identifier
enum class Agents
{
	ghost  = 'G',
	pacman = 'P',
	unkown,
};

struct Position
{
	float x{};
	float y{};
};

#endif // !GLOBALS_H

