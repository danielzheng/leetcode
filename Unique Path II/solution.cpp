#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        //change obstacle flag from 1 to -1, cause 1 means something here...
        for (auto & vi : obstacleGrid)
        {
            for (auto & v : vi)
            {
                if (v == 1)
                {
                    v = -1;
                }
            }
        }
        int columns = obstacleGrid[0].size();
        int rows = obstacleGrid.size();
        //init grid
        if (obstacleGrid[rows - 1][columns - 1] == -1 || obstacleGrid[0][0] == -1)
        {
            return 0;
        }
        obstacleGrid[rows - 1][columns - 1] = 1;

        //last row
        for (int i = columns - 2; i >= 0; i--)
        {
            if (obstacleGrid[rows - 1][i] != -1)
            {
                obstacleGrid[rows - 1][i] = obstacleGrid[rows - 1][i + 1];
            }
        }
        //last colume
        for (int j = rows - 2; j >= 0; j--)
        {
            if (obstacleGrid[j][columns - 1] != -1)
            {
                obstacleGrid[j][columns - 1] = obstacleGrid[j + 1][columns - 1];
            }
        }
        for (int i = rows - 2; i >= 0; i--)
        {
            for (int j = columns - 2; j >= 0; j--)
            {
                if (obstacleGrid[i][j] == -1)
                {
                    continue;
                }
                if (obstacleGrid[i][j + 1] != -1)
                {
                    obstacleGrid[i][j] += obstacleGrid[i][j + 1];
                }
                if (obstacleGrid[i + 1][j] != -1)
                {
                    obstacleGrid[i][j] += obstacleGrid[i + 1][j];
                }
            }
        }
        return obstacleGrid[0][0];
    }
};

int main()
{
    //vector<vector<int>> vvi{ { 0, 0} };
    vector<vector<int>> vvi{ { 0, 0, 0 }, { 0, 1, 0 }, {0, 0, 0  } };

    Solution s;
    cout << s.uniquePathsWithObstacles(vvi) << endl;
    return 0;
}
