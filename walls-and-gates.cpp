class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        // Find a gate
        for (int x = 0; x < rooms.size(); x++) {
            for (int y = 0; y < rooms[x].size(); y++) {
                if (rooms[x][y] == 0) {
                    queue<pair<int, int>> toVisit;
                    
                    toVisit.push(pair(x, y));
                    
                    while (toVisit.empty() == false) {
                        pair<int, int> coords = toVisit.front();
                        int x1 = coords.first;
                        int y1 = coords.second;
                        toVisit.pop();
​
                        int val = rooms[x1][y1];
​
                        if ((x1 - 1) >= 0)
                            if (rooms[x1 - 1][y1] > val + 1) {
                                rooms[x1 - 1][y1] = val + 1;
                                toVisit.push(pair(x1 - 1, y1));
                            }
​
                        if ((y1 - 1) >= 0)
                            if (rooms[x1][y1 - 1] > val + 1) {
                                rooms[x1][y1 - 1] = val + 1;
                                toVisit.push(pair(x1, y1 - 1));
                            }
​
                        if ((x1 + 1) < rooms.size())
                            if (rooms[x1 + 1][y1] > val + 1) {
                                rooms[x1 + 1][y1] = val + 1;
                                toVisit.push(pair(x1 + 1, y1));
                            }
​
                        if ((y1 + 1) < rooms[x].size())
                            if (rooms[x1][y1 + 1] > val + 1) {
                                rooms[x1][y1 + 1] = val + 1;
                                toVisit.push(pair(x1, y1 + 1));
                            }
                    }
                }
            }
        }
    }
};
