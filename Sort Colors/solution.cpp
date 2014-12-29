#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        redCount = 0;
        whiteCount = 0;
        blueCount = 0;
        for (int i = 0; i < n; i++)
        {
            switch (A[i])
            {
            case 0:
                redCount++;
                break;
            case 1:
                whiteCount++;
                break;
            case 2:
                blueCount++;
            default:
                break;
            }
        }
        int i = 0;
        while (redCount--)
        {
            A[i++] = 0;
        }
        while (whiteCount--)
        {
            A[i++] = 1;
        }
        while (blueCount--)
        {
            A[i++] = 2;
        }
    }
private:
    int redCount; //0
    int whiteCount; //1
    int blueCount; //2
};

int main()
{
    int A[] = {0, 1, 1, 0, 2, 2, 1, 1, 1, 0, 0, 0};
    Solution s;
    s.sortColors(A, sizeof(A) / sizeof(int));
    for (auto i : A)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
