#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
      //基本字符    I   V   X   L   C   D   M
      //阿拉伯数字  1   5   10  50  100 500 1000
      map<char, short> romanMap ={{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}; 
      int num = 0;
      for (size_t i = 0; i < s.size(); ++i)
      {
          if (i == (s.size() - 1))
          {
              num += romanMap[s[i]];
          }
          else if (romanMap[s[i]] < romanMap[s[i + 1]])
          {
              num += (romanMap[s[i + 1]] - romanMap[s[i]]);
              ++i;
          }
          else
          {
              num += romanMap[s[i]];
          }
      }
      return num;
    }
};

int main()
{
    Solution s;
    string romanNumber = "MCMXCIII";
    std::cout << "Number of " << romanNumber << " is " << s.romanToInt(romanNumber) << std::endl;
    return 0;
}
