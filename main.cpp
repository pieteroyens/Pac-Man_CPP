#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <string_view>

#include "Map.h"
#include "Constants.h"
#include "Visualizer.h"
#include "TileObject.h"
#include "Level.h"
#include "LevelFactory.h"
#include "FPS.h"

int main()
{
    // choose level
    std::string level_file{ "levels/original.txt" };
    //std::string level_file{ "levels/small.txt" };

    Level level{ generate_level(level_file) };

    // create window of x by y pixels with a name
    sf::RenderWindow window(
        sf::VideoMode(level.get_level_map().get_dimenison().width * Map_Constants::TILE_SIZE,
                      level.get_level_map().get_dimenison().height * Map_Constants::TILE_SIZE), "Pac-Man");

    // Initialize the clock, it starts automatically
    // Measure all time in microseconds as its an Int64, so no rounding error
    // (Time seconds is a float in SFML)
    // Used to make the game update frame-rate independent
    sf::Clock clock{};
    sf::Time lag = sf::microseconds(0);

       

    // Setting the frame duration at ~60FPS (16.67 milliseconds)
    const sf::Time FRAME_DUR{ sf::microseconds(16667) };

    //FPS fps;
    // run the game for as long as the window remain open
    while (window.isOpen())
    {
        // Game Loop: following this design pattern: https://gameprogrammingpatterns.com/game-loop.html#you-may-need-to-coordinate-with-the-platform's-event-loop
        // Restarting the clock return the elapsed time
        sf::Time elapsed_time{ clock.restart() };
        lag += elapsed_time;
          
        // Update the game not more than X Frames duration (measured in microseconds) per second 
        // So If we have very little lag, we skip the update loop, if we have a lot of lag, we do the update loop
        while (lag >= FRAME_DUR)
        {
            lag -= FRAME_DUR;

            // check all the windo's events that were triggered, SFML specific
            // implement a switch case when we want to get player input
            // implement maybe a pause if the game is out of focus

            sf::Event event;
            while (window.pollEvent(event))
            {
                // close button was pressed, close the window
                if (event.type == sf::Event::Closed)
                    window.close(); 
            }

            // Process User Input
            // Update Game State: AI and "Physics" (in this order)
            // Do we need to pass something to the update() function?
            level.Update();
        }

        // Render the game
        window.clear();
        draw_level(window, level);
        window.display();
        
        //Remove later
        //fps.update();
        //std::cout << "FPS: " << fps.getFPS() << '\r';

    }
	
	return 0;
}
