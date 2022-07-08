#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <array>

#include "Constants.h"
#include "GameObject.h"
#include "TileObject.h"

class Map
{
private:
	std::vector<std::vector<TileObject> > m_tile_grid{};

	struct MapDimension // in tiles
	{
		int width{};
		int height{};
	};

	MapDimension m_dimension{};

public:
	//Map(const std::string& level_file);
	Map(std::vector<std::vector<TileObject>> tile_grid) : m_tile_grid{ tile_grid }
	{
		m_dimension.height = static_cast<int>(tile_grid.size());
		m_dimension.width = static_cast<int>(tile_grid[0].size());
	};
	
	std::vector<std::vector<TileObject> > get_tile_grid() { return m_tile_grid; }

	const MapDimension& get_dimenison() { return m_dimension; };

	//int Pellets_Left();
};

#endif