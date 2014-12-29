#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if ((m + n) % 2)
		{
			return findKth(A, 0, m - 1, B, 0, n - 1, (m + n) / 2 + 1);
		}
		else
		{
			return (findKth(A, 0, m - 1, B, 0, n - 1, (m + n) / 2) +
				findKth(A, 0, m - 1, B, 0, n - 1, (m + n) / 2 + 1)) / 2.0;
		}
	}
private:
	double findKth(int A[], int aBegin, int aEnd, int B[], int bBegin, int bEnd, int k)
	{
		int aLength = aEnd - aBegin + 1;
		int bLength = bEnd - bBegin + 1;
		if (aLength == 0)
		{
			return B[k - 1];
		}
		if (bLength == 0)
		{
			return A[k - 1];
		}
		if (k == 1)
		{
			return min(A[aBegin], B[bBegin]);
		}
		if (aLength > bLength)
		{
			return findKth(B, bBegin, bEnd, A, aBegin, aEnd, k);
		}
		int disposeA = min(aLength, k / 2);
		int disposeB = k - disposeA;
		if (A[aBegin + disposeA - 1] == B[bBegin + disposeB - 1])
		{
			return A[aBegin + disposeA - 1];
		}
		else if (A[aBegin + disposeA - 1] > B[bBegin + disposeB - 1])
		{
			return findKth(A, aBegin, aEnd, B, bBegin + disposeB, bEnd, k - disposeB);
		}
		else
		{
			return findKth(A, aBegin + disposeA, aEnd, B, bBegin, bEnd, k - disposeA);
		}
	}
};

int main()
{
	int A[] = { 2, 4 };
	int B[] = { 1, 3, 4 };
	Solution s;
	cout << s.findMedianSortedArrays(A, sizeof(A) / sizeof(int), B, sizeof(B) / sizeof(int)) << endl;
	vector<int> vi;
	for (auto i : A)
	{
		vi.push_back(i);
	}
	for (auto i : B)
	{
		vi.push_back(i);
	}
	sort(vi.begin(), vi.end());
	if (vi.size() % 2)
	{
		cout << "correct answer = " << vi[vi.size() / 2] << endl;
	}
	else
	{
		cout << "correct answer = " << (vi[vi.size() / 2] + vi[vi.size() / 2 - 1]) / 2.0 << endl;
	}
	return 0;
}
