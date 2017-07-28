//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.


#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        string intToRoman(int num) {
            string thousand[] = {"", "M", "MM", "MMM"};
            string hundred[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
            string ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
            string one[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
            return thousand[num / 1000] + hundred[(num % 1000) / 100] + ten[(num % 100) / 10] + one[num % 10];
        }
};

int main()
{
    Solution s;
    int num =  1255;
    std::cout << "Roman Number of " << num << " is " << s.intToRoman(num) << std::endl;
    return 0;
}
