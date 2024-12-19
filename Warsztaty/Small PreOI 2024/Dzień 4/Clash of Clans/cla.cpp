#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

void readInput (int& n , int& m , vector<string>& verticalEdges , vector<string>& horizontalEdges)
{
    cin >> n >> m;
    verticalEdges.resize (m);
    horizontalEdges.resize (m - 1);

    for (int i = 0; i < m; ++i)
    {
        cin >> verticalEdges[i];
    }
    for (int i = 0; i < m - 1; ++i)
    {
        cin >> horizontalEdges[i];
    }
}

bool isValid (int x , int y , int n , int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs (int startX , int startY , vector<vector<bool>>& visited , vector<string>& verticalEdges , vector<string>& horizontalEdges , int n , int m)
{
    queue<pair<int , int>> q;
    q.emplace (startX , startY);

    while (!q.empty ())
    {
        auto [x , y] = q.front ();
        q.pop ();

        if (visited[x][y]) continue;
        visited[x][y] = true;

        // Check neighbors
        const vector<pair<int , int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;

            if (isValid (nx , ny , n , m) && !visited[nx][ny])
            {
                if (i == 0 && x > 0 && horizontalEdges[x - 1][y] != '.') q.emplace (nx , ny); // Top
                if (i == 1 && x < n - 1 && horizontalEdges[x][y] != '.') q.emplace (nx , ny); // Bottom
                if (i == 2 && y > 0 && verticalEdges[y - 1][x] != '.') q.emplace (nx , ny);   // Left
                if (i == 3 && y < m - 1 && verticalEdges[y][x] != '.') q.emplace (nx , ny);   // Right
            }
        }
    }
}

int main ()
{
    int n , m;
    vector<string> verticalEdges;
    vector<string> horizontalEdges;

    readInput (n , m , verticalEdges , horizontalEdges);

    vector<vector<bool>> visited (n , vector<bool> (m , false));

    // Perform BFS from both gates
    bfs (0 , m / 2 , visited , verticalEdges , horizontalEdges , n , m);
    bfs (n - 1 , m / 2 , visited , verticalEdges , horizontalEdges , n , m);

    // Count walls and maximize chrom walls
    int totalWalls = 0;
    int chromWalls = 0;

    // Update the grid with walls
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            if (verticalEdges[i][j] == 'C')
            {
                totalWalls++;
                chromWalls++;
                verticalEdges[i][j] = 'Z';
            }
            else if (verticalEdges[i][j] == 'T')
            {
                totalWalls++;
                verticalEdges[i][j] = 'Z';
            }
        }
    }
    for (int i = 0; i < m - 1; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (horizontalEdges[i][j] == 'C')
            {
                totalWalls++;
                chromWalls++;
                horizontalEdges[i][j] = 'Z';
            }
            else if (horizontalEdges[i][j] == 'T')
            {
                totalWalls++;
                horizontalEdges[i][j] = 'Z';
            }
        }
    }

    // Output the result
    cout << totalWalls << " " << chromWalls << endl;

    // Print the updated grid
    for (const auto& row : verticalEdges)
    {
        cout << row << endl;
    }
    for (const auto& row : horizontalEdges)
    {
        cout << row << endl;
    }

    return 0;
}
