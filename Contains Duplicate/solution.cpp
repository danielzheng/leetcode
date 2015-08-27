#include <vector>
#include <iostream>
#include <bitset>
#include <unordered_set>
#include <limits.h>
using namespace std;


class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		for (const auto& n : nums)
		{
			if (hash.count(n) > 0)
			{
				return true;
			}
			hash.insert(n);
		}
		return false;
	}
private:
	unordered_set<int> hash;
};

int main()
{
	vector<int> v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
	}
	v.push_back(50);
	Solution s;
	cout << boolalpha << s.containsDuplicate(v) << endl;
	return 0;
}
