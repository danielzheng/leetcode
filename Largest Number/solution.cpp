class Solution {
public:
    string largestNumber(vector<int> &num) {
        int sum = accumulate(num.begin(), num.end(), 0);
        if (sum == 0)
        {
            return "0";
        }
        vector<string> vs;
        for (const auto& n : num)
        {
            vs.push_back(to_string(n));
        }
        auto func = [&](string i, string j)
        {
            return i + j < j + i;
        };
        sort(vs.begin(), vs.end(), func);
        string result;
        for (const auto& str : vs)
        {
            result = str + result;
        }
        return result;
    }
};
