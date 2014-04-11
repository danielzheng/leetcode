class Solution {
public:
    void reverseWords(string &s) {
		if (s.empty())
		{
			return;
		}
		//trim
		s.erase(0, s.find_first_not_of(' '));
		s.erase(s.find_last_not_of(' ') + 1);
		//remove duplicate space
		auto new_end = unique(s.begin(), s.end(), [](const char& c1, const char& c2) { return c1 == ' ' && c1 == c2;});
		s = string(s.begin(), new_end);
		reverse(s.begin(), s.end());
		for (int end = 0; end < s.size(); end++)
		{
			int begin = end;
			while (end < s.size() && s[end] != ' ')
			{
				end++;
			}
			reverse(&s[begin], &s[end]);
		} 
    }
};
