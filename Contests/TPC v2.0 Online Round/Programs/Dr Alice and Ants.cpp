#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 150 + 5, NO_OF_NEIGHBOURS = 4, UNVISITED = -1;
int grid[MAX_N][MAX_N], distance_graph[MAX_N][MAX_N];
int next_x[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1};
int next_y[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};

int main()
{
    memset(distance_graph, UNVISITED, sizeof(distance_graph));
    
    int rows, columns;
    cin >> rows >> columns;
    
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            cin >> grid[i][j];
        }
    }
    
    queue <pair <int, int> > Q;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            if(grid[i][j] == 1)
            {
                Q.push(make_pair(i, j));
                
                distance_graph[i][j] = 0;
            }
        }
    }
    
    while(Q.size() > 0)
    {
        pair <int, int> now = Q.front();
        Q.pop();
        
        int x = now.first, y = now.second;
        
        for(int n = 0; n < NO_OF_NEIGHBOURS; n++)
        {
            int new_x = x + next_x[n];
            int new_y = y + next_y[n];
            
            if(1 <= new_x && new_x <= rows &&
               1 <= new_y && new_y <= columns &&
               distance_graph[new_x][new_y] == UNVISITED)
               {
                   distance_graph[new_x][new_y] = 1 + distance_graph[x][y];
                   
                   Q.push(make_pair(new_x, new_y));
               }
        }
    }
    
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            cout << distance_graph[i][j] << " ";
        }
        
        cout << "\n";
    }
    return 0;
}
