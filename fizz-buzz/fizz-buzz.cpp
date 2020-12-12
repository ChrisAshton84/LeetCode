class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i = 1; i <= n; i++) {
            if ((i % 15) == 0)
                ret.emplace_back("FizzBuzz");
            else if ((i % 5) == 0)
                ret.emplace_back("Buzz");
            else if ((i % 3) == 0)
                ret.emplace_back("Fizz");
            else
                ret.emplace_back(to_string(i));
        }
        return ret;
    }
};
