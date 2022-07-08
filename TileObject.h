#include "GameObject.h"
#include "Globals.h"

#ifndef TILE_OBJECT_H
#define TILE_OBJECT_H

class TileObject : public GameObject
{
private:
	Tiles m_tileType{};

public:
	TileObject() : m_tileType{ Tiles::empty } {} ;
	TileObject(Tiles tyleType) : m_tileType{ tyleType } {};

	const Tiles getTileType() { return m_tileType; }
	void setTileType(Tiles tyleType) { m_tileType = tyleType; }
};

#endif // !TILE_OBJECT_H



