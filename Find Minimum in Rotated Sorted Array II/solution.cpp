nclude <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size() - 1);
    }
private:
    int findMin(const vector<int> &num, int begin, int end)
    {
        if (begin == end)
        {
            return num[begin];
        }
        else if (num[begin] >= num[end])
        {
            int middle = (begin + end) / 2;
            return min(findMin(num, begin, middle), findMin(num, middle + 1, end));
        }
        return num[begin];
    }
};

int main()
{
    vector<int> vi{4, 5, 6,7, 0, 0, 0, 1,2, 4};
    Solution s;
    cout << s.findMin(vi) << endl;
    return 0;
}
