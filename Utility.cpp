#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>

#include "Utility.h"

std::vector<std::string> read_level(const std::string& level_loc)
{
	std::cout << "Reading File " << '\n';
	
	// ifstream expect a const *char or const std::string&
	std::ifstream inf{ level_loc };

	if (!inf)
	{
		std::cerr << "Level file not found!\n";
	}
	
	// Store the map/level data in here
	std::vector<std::string> mapRows{};

	while (inf)
	{
		std::string strInput;
		std::getline(inf, strInput);
		// Expensive operation, but we only have to do it once.
		// This way, map height is also not constant, and we let it depend on the text file.
		mapRows.push_back(strInput);
	}

	// perform some checks if the map file adheres to basic criteria
	// width, height, pacman and pellets

	return mapRows;
}