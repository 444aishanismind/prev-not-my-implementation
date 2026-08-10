#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
       
        visited[room] = true;
        
      
        for (int key : rooms[room]) {
          
            if (!visited[key]) {
                dfs(key, rooms, visited);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        // Always start at room 0
        dfs(0, rooms, visited);
        
        //  if any room is still false we failed to unlock everything
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        
        // Every single room was successfully visited
        return true;
    }
};