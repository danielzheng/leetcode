#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        int i = 1;
        int j = 0;
        while ((j = n / (int)pow(5, i++)) > 0)
        {
            result += j;
        }
        return result;
    }
};

int main()
{
    int num = 20;
    long long f = 1;
    Solution s;
    cout << s.trailingZeroes(num) << endl;
    for (int i = 1; i <= num; i++)
    {
        f = f * i;
    }
    cout << f << endl;
    return 0;
}
