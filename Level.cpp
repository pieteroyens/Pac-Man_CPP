#include <iostream>
#include <SFML/Window.hpp>

#include "Level.h"
#include "Agent.h"
#include "GameObject.h"
#include "Constants.h"

void Level::Update()
{
	std::cout << "Updating Level\n";
	Agent& pacman = m_agents[0]; // pacman is always the first agent in the list

    //some movement logic
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        pacman.updatePosition(Character_Constants::PAC_MAN_SPEED, 0.0);
        std::cout << "Right key pressed\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        pacman.updatePosition(-5.0f, 0.0f);
        std::cout << "Left key pressed\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        pacman.updatePosition(0.0f, -5.0f);
        std::cout << "Up key pressed\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        pacman.updatePosition(0.0f, 5.0f);
        std::cout << "Down key pressed\n";
    }
}