#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b)
                {
                return a.start < b.start;
                });
        vector<Interval> ret;
        for (const auto& e : intervals)
        {
            auto lastOne = ret.rbegin();
            if (lastOne == ret.rend())
            {
                ret.push_back(e);
            }
            else if (lastOne->end < e.start)
            {
                ret.push_back(e);
            }
            else if (lastOne->end < e.end)
            {
                lastOne->end = e.end;
            }
        }

        return ret;
    }
};

int main()
{
    //[1,3],[2,6],[8,10],[15,18]
    //vector<Interval> vi {Interval(1, 3), Interval(2, 6), Interval(8, 20), Interval(15, 18)};
    vector<Interval> vi {Interval(8, 20), Interval(2, 6), Interval(1, 3), Interval(15, 18)};

    Solution s;
    auto ret = s.merge(vi);

    for (const auto& e : ret)
    {
        std::cout << "[" << e.start << ", " << e.end << "] ";
    }
    std::cout << endl;
    return 0;
}
