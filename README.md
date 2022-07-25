# Pac-Man CPP
A C++ implementation of Pac-Man and is first project for learning C++. This project was made in a couple of days to get to grips with the language.

There are a few critical things missing/lacking code-wise.
   - No const variable use.
   - AIManager::euclideanPlan takes  std::vector<std::tuple<TileObject, Agent::direction>> by value, this should be passed by reference.
   - Euclidean distance is an expensive operation, this can easily be Manhatten distance.
   - Ghosts escape there enclosure in a hacky way (hard-coded).
   
There are also a few flaws design-wise, namely that the ghosts cannot turn back and that they don't use more sophistiacted path-finding algorithms (like A*).
Due to setting myself with a time constraints, the code is not perfect, but the main issues have bean adressed and I will leave improvements up for a future implementation!
