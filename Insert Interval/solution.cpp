#include <iostream>
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
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> ret;
    bool inserted = false;
    for (const auto &e : intervals) {
      if (inserted) {
        ret.push_back(e);
      } else {
        if (e.start < newInterval.start) {
          ret.push_back(e);
        } else {
          ret.push_back(newInterval);
          ret.push_back(e);
          inserted = true;
        }
      }
    }
    if (!inserted)
    {
        ret.push_back(newInterval);
    }

    return merge(ret);
  }
  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> ret;
    for (const auto &e : intervals) {
      auto lastOne = ret.rbegin();
      if (lastOne == ret.rend()) {
        ret.push_back(e);
      } else if (lastOne->end < e.start) {
        ret.push_back(e);
      } else if (lastOne->end < e.end) {
        lastOne->end = e.end;
      }
    }

    return ret;
  }
};

int main()
{
    //vector<Interval> vi {Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16)};
    //vector<Interval> vi {Interval(1, 5)};
    vector<Interval> vi;
    Interval newInterval(2, 7);
    
    Solution s;
    auto ret = s.insert(vi, newInterval);

    for (const auto& e : ret)
    {
        std::cout << "[" << e.start << ", " << e.end << "] "; 
    }
    std::cout << std::endl;

    return 0; 
}

