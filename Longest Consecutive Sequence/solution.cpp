class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		if (num.empty())
		{
			return 0;
		}
		for (int i = 0; i < num.size(); i++)
		{
			hashset.insert(num[i]);
		}
		int maxLen = 0;
		for (int i = 0; i < num.size(); i++)
		{
			maxLen = max(maxLen, 1 + findConsecutive(INCREMENT, num[i]) + findConsecutive(DECREMENT, num[i]));
		}
		return maxLen;
	}
private:
	enum DIRECTION
	{
		INCREMENT,
		DECREMENT
	};
	int findConsecutive(DIRECTION dir, int num)
	{
		int len = 0;
		if (dir == INCREMENT)
		{
			while (hashset.find(++num) != hashset.end())
			{
				++len;
				hashset.erase(num);
			}

		}
		else
		{
			while (hashset.find(--num) != hashset.end())
			{
				++len;
				hashset.erase(num);
			}
		}
		return len;
	}
	unordered_set<int> hashset;
};