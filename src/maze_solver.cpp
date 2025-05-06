#include "maze_solver.h"
#include <stack>
using namespace std;

bool MazeSolver::dfs(Maze& maze, int r, int c, vector<vector<bool>>& visited) {
    if (r < 0 || r >= static_cast<int>(maze.grid.size()) ||
        c < 0 || c >= static_cast<int>(maze.grid[0].size()) ||
        maze.grid[r][c] == '#' || visited[r][c]) {
        return false;
    }

    if (maze.grid[r][c] == 'F') {
        maze.path.push_back({r, c});
        return true;
    }
    visited[r][c] = true;

    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int new_r = r + dr[i];
        int new_c = c + dc[i];

        if (dfs(maze, new_r, new_c, visited)) {
            maze.path.push_back({r, c});
            return true;
        }
    }
    return false;
}

bool MazeSolver::solveDFS(Maze& maze) {
    // Clear any existing path
    maze.path.clear();
    
    // Create visited matrix
    vector<vector<bool>> visited(maze.grid.size(), 
                               vector<bool>(maze.grid[0].size(), false));
    
    // Start DFS from the start position
    bool found = dfs(maze, maze.start.row, maze.start.col, visited);
    
    // If path found, add the start position to the path
    if (found) {
        maze.path.push_back(maze.start);
    }
    
    return found;
}
