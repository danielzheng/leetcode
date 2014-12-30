#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int index = binarySearch(A, 0, n - 1, target);
        range = { -1, -1 };
        if (index == -1)
        {
            return range;
        }
        int i = index;
        int j = index;
        while (i >=0 && A[i] == target)
        {
            range[0] = i;
            i--;
        }
        while (j < n && A[j] == target)
        {
            range[1] = j;
            j++;
        }
        return range;
    }
private:
    int binarySearch(int A[], int begin, int end, int target)
    {
        if (begin > end)
        {
            return -1;
        }
        int mid = (begin + end) / 2;
        if (A[mid] == target)
        {
            return mid;
        }
        else if (A[mid] < target)
        {
            return binarySearch(A, mid + 1, end, target);
        }
        else
        {
            return binarySearch(A, begin, mid - 1, target);
        }
    }
    vector<int> range;
};

int main()
{
    int A[] = { 5, 7, 7 };
    Solution s;
    auto vi = s.searchRange(A, sizeof(A) / sizeof(int), 8);
    for (const auto i : vi)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
