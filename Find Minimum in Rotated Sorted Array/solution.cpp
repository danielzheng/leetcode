#include <iostream>
#include <vector>

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
        if (num[begin] > num[end])
        {
            int tmp = (begin + end) / 2;
            if (num[begin] > num[tmp])
            {
                return findMin(num, begin, tmp);
            }
            else
            {
                return findMin(num, tmp + 1, end);
            }
        }
        return num[begin];
    }
};

int main()
{
    //vector<int> vi{ 4, 5, 6, 7, 0, 1, 2 };
    vector<int> vi{ 100 };
    Solution s;
    cout << s.findMin(vi) << endl;
    return 0;
}
