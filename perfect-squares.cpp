class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        
        for (int i = 1; i*i <= n; i++)
            squares.emplace_back(i *i);
​
        queue<int> remaining;
        remaining.push(n);
        int level = 0;
        
        while (true) { // There will always be a solution - if nothing else, 1's
            level++;
            
            int level_count = remaining.size();
            
            for (int i = 0; i < level_count; i++) {
                int num = remaining.front();
                remaining.pop();
​
                for (int j = squares.size() - 1; j >= 0; j--) {
                    if (squares[j] == num)
                        return level;
                    if (squares[j] < num)
                        remaining.push(num - squares[j]);
                }
            }
        }
    }
};
