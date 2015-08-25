#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int>hash1;
		unordered_map<char, int>hash2;

		for (const auto& c : s)
		{
			++hash1[c];
		} 

		for (const auto& c : t)
		{
			++hash2[c];
		} 
		return (hash1 == hash2);
	}
};

int main()
{
	Solution s;
	cout << boolalpha << s.isAnagram("abac", "aacb") << endl;
	return 0;
}
