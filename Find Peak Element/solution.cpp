#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() == 1)
        {
            return 0;
        }
        for (int i = 1; i < num.size() - 1; i++)
        {
            if (num[i] > num[i - 1] && num[i] > num[i + 1])
            {
                return i;
            }
        }
        if (num[num.size() - 1] > num[num.size() - 2])
        {
            return num.size() - 1;
        }
        return 0;
    }
};

int main()
{
    //vector<int> vi{ 1, 2, 3, 4, 5 };
    vector<int> vi{ 1, 3, 5, 4, 3, 2, 1 };
    Solution s;
    cout << s.findPeakElement(vi) << endl;

    return 0;
}
