class Solution {
public:
	int titleToNumber(string s) {
		int num = 0;
		char shift = 'A' - 1;
		for (auto it = s.begin(); it != s.end(); ++it)
		{
			num = num * 26 + *it - shift;
		}
		return num;
	}
};
