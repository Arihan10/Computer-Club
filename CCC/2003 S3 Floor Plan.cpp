#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std; 

int main () {
    int flooring, rows, columns; 
    cin >> flooring >> rows >> columns; 
    char floorplan[rows][columns]; 
    bool visited[rows][columns]; 

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> floorplan[i][j]; 
        }
    }

    vector<int> roomSizes; 

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (floorplan[i][j] == '.' && !visited[i][j]) {

                //Breadth First Search
                int floorSpace = 1; 

                queue<pair<int, int>> q; 
                q.push(make_pair(i, j)); 
                visited[i][j] = true; 

                while (!q.empty()) {
                    pair<int, int> node = q.front(); 

                    int x = node.first; 
                    int y = node.second; 

                    if (floorplan[x-1][y] == '.' && !visited[x-1][y]) {
                        q.push(make_pair(x-1, y)); 
                        visited[x-1][y] = true; 
                        ++floorSpace; 
                    }

                    if (floorplan[x+1][y] == '.' && !visited[x+1][y]) {
                        q.push(make_pair(x+1, y)); 
                        visited[x+1][y] = true; 
                        ++floorSpace; 
                    }

                    if (floorplan[x][y-1] == '.' && !visited[x][y-1]) {
                        q.push(make_pair(x, y-1)); 
                        visited[x][y-1] = true; 
                        ++floorSpace; 
                    }

                    if (floorplan[x][y+1] == '.' && !visited[x][y+1]) {
                        q.push(make_pair(x, y+1)); 
                        visited[x][y+1] = true; 
                        ++floorSpace; 
                    }

                    q.pop(); 
                }

                roomSizes.push_back(floorSpace); 
            }
        }
    }

    sort(roomSizes.begin(), roomSizes.end()); 

    int totalRoomSize = 0, roomsFloored = 0; 
    for (int i = roomSizes.size()-1; i >= 0; --i) {
        if (totalRoomSize + roomSizes[i] > flooring) {
            break; 
        }

        totalRoomSize += roomSizes[i]; 
        ++roomsFloored; 
    }

    cout << roomsFloored << " rooms, " << flooring-totalRoomSize << " square metre(s) left over\n"; 
}