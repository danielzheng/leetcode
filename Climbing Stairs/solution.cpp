#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        return clibmStairsi3(n);
    }
private:
    void climbStairs(int n, int steps)
    {
        n -= steps;
        if (n == 0)
        {
            count++;
            return;
        }
        else if (n < 0)
        {
            return;
        }
        else
        {
            climbStairs(n, 1);
            climbStairs(n, 2);
        }
    }
    
    void climbStairs2(int n, int steps)
    {
        if (steps > n)
        {
            return;
        }
        else if (steps == n)
        {
            count++;
        }
        else
        {
            climbStairs2(n, steps + 1);
            climbStairs2(n, steps + 2);
        }
    }
    //correct one
    int clibmStairsi3(int n)
    {
        if (n < 3)
        {
            return n;
        }
        int prev2 = 1;
        int prev1 = 2;
        int result = 0;
        for (int i = 3; i <= n; i++)
        {
            result = prev1 + prev2;
            prev2 = prev1;
            prev1 = result;
        }
        return result;
    }
    int count;
};

int main()
{
    int n = 10;
    Solution s;
    cout << s.climbStairs(n) << endl;
    return 0;
}
