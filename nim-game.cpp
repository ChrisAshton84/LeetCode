class Solution {
public:
    bool canWinNim(int n) {
        return (n & 0b11) != 0;
    }
};
