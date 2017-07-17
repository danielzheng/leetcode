#include <iostream>
#include <string>

using namespace std;


class Solution {
    public:
        int lengthOfLastWord(string s) {
            int len = 0;
            bool getFirstChar = false;
            for (auto rit = s.rbegin(); rit != s.rend(); ++rit)
            {
                if (*rit == ' ')
                {
                    if (getFirstChar)
                    {
                        return len;

                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    getFirstChar = true;
                    ++len;
                }
            }

            return len;
        }
};

int main()
{
    string s1 = "Hello World";
    string s2 = "aa bbb ccc eee";
    string s3 = "";
    string s4 = "aaaaa";
    string s5 = "a ";

    Solution s;

    std::cout << s1 << " " << s.lengthOfLastWord(s1) << std::endl;
    std::cout << s2 << " " << s.lengthOfLastWord(s2) << std::endl;
    std::cout << s3 << " " << s.lengthOfLastWord(s3) << std::endl;
    std::cout << s4 << " " << s.lengthOfLastWord(s4) << std::endl;
    std::cout << s5 << " " << s.lengthOfLastWord(s5) << std::endl;


    return 0;
}
