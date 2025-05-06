#pragma once
#include "maze.h"
#include <vector>
#include <utility> // for std::pair

using namespace std;

class MazeSolver {
public:
    // returns true and fills maze.path if a path exists from S to F.
    bool solveDFS(Maze& maze);

private:
    // recursive helper for DFS with backtracking.
    bool dfs(Maze& maze, int r, int c, vector<vector<bool>>& visited);
};
