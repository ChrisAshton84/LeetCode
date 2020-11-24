class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;
        
        if (grid[0].size() == 0)
            return 0;
        
        auto lsize = grid[0].size();
        
        typedef struct {
            int start;
            int end;
            int id;
            int joined;
        } island_info_t;
​
        vector<island_info_t> prevIslands;
        vector<island_info_t> curIslands;
​
        int ret = 0;
        int prevID = 0;
        
        // Scan forward line-by-line
        for (int l = 0; l < grid.size(); l++) {
            auto &line = grid[l];
            curIslands.clear();
            
            // First generate a list of the islands on this line
            for (int i = 0; i < lsize; i++) {
                if (line[i] == '1') {
                    auto start = i;
                    auto end = i;
                    
                    while (((end + 1) < lsize) && (line[end + 1] == '1'))
                        end++;
                    
                    // Emplace islands *in order*
                    curIslands.emplace_back(island_info_t{start, end, 0, 0});
                    
                    i = end;
                }
            }
            
            // Next compare and merge with any islands from previous line
            for (auto& curIsland: curIslands) {
                for (auto& prevIsland: prevIslands) {
                    // Islands are ordered, so if we've gone too far, done with this island
                    if (prevIsland.start > curIsland.end)
                        break;
​
                    // Check for intersection
                    if (((curIsland.start >= prevIsland.start) && (curIsland.start <= prevIsland.end) ||
                        ((curIsland.end >= prevIsland.start) && (curIsland.end <= prevIsland.end))) ||
                        ((curIsland.start <= prevIsland.start) && (curIsland.end >= prevIsland.end))) {
                        // These islands intersect - merge this with the previous island
                        // If this island has no id, it needs prev island's id
                        if (curIsland.id == 0)
                            curIsland.id = prevIsland.id;
                        // Otherwise, this island already found one match and it will be
                        // merging in a second island, which should become the same id,
                        // along with any other island sharing it
                        else if (curIsland.id != prevIsland.id) {
                            int oldID = max(prevIsland.id, curIsland.id);
                            int newID = min(prevIsland.id, curIsland.id);
                            
                            for (auto& ii: prevIslands) {
                                if (ii.id == oldID)
                                    ii.id = newID;
                            }
                            for (auto& ii: curIslands) {
                                if (ii.id == oldID)
                                    ii.id = newID;
                            }
                        }
                        
                        // Note that the prev island was joined w/ this one
                        prevIsland.joined = 1;
                        
                        for (auto& i: prevIslands) {
                            if (i.id == prevIsland.id)
                                i.joined = true;
                        }
                    }
                }
                
                // No intersection w/ previous island, so needs new id
                if (curIsland.id == 0)
                    curIsland.id = ++prevID;
            }
            
            // Now, look at previous line - any island pieces that weren't joined need to be
            // removed and tested to see whether that island is complete
            for (int i = 0; i < prevIslands.size(); i++) {
                if (prevIslands[i].joined == 0) {
                    for (int j = 0; j < prevIslands.size(); j++) {
                        if (prevIslands[j].id == prevIslands[i].id)
                            prevIslands[j].joined = 1; // Now use this to signify it's been added to the result
                    }
                    
                    //cout << "Ended an island on line " << l << ", range=" << prevIslands[i].start << "," << prevIslands[i].end << ", id=" << prevIslands[i].id << endl;
                    
                    ret++;
                }
            }
            
            prevIslands = curIslands;
        }
            
        // Now, look at previous line - any island pieces that weren't joined need to be
        // removed and tested to see whether that island is complete
        for (int i = 0; i < prevIslands.size(); i++) {
            if (prevIslands[i].joined == 0) {
                for (int j = 0; j < prevIslands.size(); j++) {
                    if (prevIslands[j].id == prevIslands[i].id)
                        prevIslands[j].joined = 1; // Now use this to signify it's been added to the result
                }
​
                //cout << "Ended an island at end, range=" << prevIslands[i].start << "," << prevIslands[i].end << ", id=" << prevIslands[i].id << endl;
​
                ret++;
            }
        }
​
        return ret;
    }
};
