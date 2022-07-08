#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "Constants.h"
#include "Visualizer.h"
#include "Map.h"
#include "GameObject.h"
#include "TileObject.h"
#include "Agent.h"
#include "Level.h"

void draw_tile(sf::RenderWindow& window, TileObject tile)
{
	switch (tile.getTileType())
	{
	case(Tiles::wall):
	{
		sf::RectangleShape rectangle(
			sf::Vector2f(Map_Constants::TILE_SIZE, Map_Constants::TILE_SIZE));

		rectangle.setPosition(tile.getPosition().x, tile.getPosition().y);
		rectangle.setFillColor(sf::Color::Blue);

		window.draw(rectangle);
		break;
	}
	case Tiles::pellet: // draw as a small circle
	{
		constexpr float radius{ Map_Constants::TILE_SIZE / 8.0f };
		sf::CircleShape circle(radius);
		float offset{ (Map_Constants::TILE_SIZE / 2.0f) - radius};
		circle.setPosition(tile.getPosition().x + offset, tile.getPosition().y + offset);
		circle.setFillColor(sf::Color::Magenta);

		window.draw(circle);
		break;
	}
	case Tiles::super_pellet: // draw as a larger circle than pellet
	{
		constexpr float radius{ Map_Constants::TILE_SIZE / 4.0f };
		sf::CircleShape circle(radius);
		float offset{ (Map_Constants::TILE_SIZE / 2.0f) - radius };
		circle.setPosition(tile.getPosition().x + offset, tile.getPosition().y + offset);
		circle.setFillColor(sf::Color::Green);

		window.draw(circle);
		break;
	}
	case Tiles::teleport: // for now, draw it as a lighter tile
		break;
	case Tiles::empty: // don't draw anything for a pellet
		break;
	default:
		break;
	}
}

void draw_agent(sf::RenderWindow& window, Agent agent)
{
	constexpr float radius{ Map_Constants::TILE_SIZE / 2.0f };
	sf::CircleShape circle(radius);
	float offset{ (Map_Constants::TILE_SIZE / 2.0f) - radius };
	circle.setPosition(agent.getPosition().x + offset, agent.getPosition().y + offset);
	
	switch (agent.get_agent_type())
	{
	case(Agents::pacman): circle.setFillColor(sf::Color::Yellow); break;
	case(Agents::ghost):  circle.setFillColor(sf::Color::Cyan); break;
	default: break;
	}
	window.draw(circle);
}

//void draw_level (sf::RenderWindow& window, Map& map) 
void draw_level(sf::RenderWindow& window, Level& level)
{
	/*std::vector<std::vector<TileObject>> grid = map.get_tile_grid();*/
	std::vector<std::vector<TileObject>> grid = level.get_level_map().get_tile_grid();
	for (int row = 0; row < level.get_level_map().get_dimenison().height; ++row)
	{
		for (int column = 0; column < level.get_level_map().get_dimenison().width; ++column)
		{
			TileObject& currentTile = grid[row][column];
			draw_tile(window, currentTile);
		}
	}

	for (Agent& agent : level.get_agents())
		draw_agent(window, agent);
}