#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix[0].size();
        // A[i][j] == > A[j][n - i - 1]
        // A[j][n - i - 1] ==> A[n - i - 1][n - j - 1]
        // A[n - i - 1][n - j - 1] == > A[n - j - 1][i]
        // A[n - j - 1][i] ==> A[i][j]
        for (int begin = 0, end = n - 2, row = 0; begin <= end; begin++, end--, row++)
        {
            int j = begin;
            int i = row;
            while (j <= end)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
                j++;
            }
        }
    }
};

int main()
{
    vector<vector<int>> vvi{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    //vector<vector<int>> vvi{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, {13, 14, 15, 16} };
    Solution s;
    s.rotate(vvi);
    return 0;
}
