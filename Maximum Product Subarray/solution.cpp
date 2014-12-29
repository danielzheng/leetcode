#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n) {
		int result = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				result = max(result, getRangeProduct(A, i, j));
			}
		}
		return result;
	}

	int maxProduct2(int A[], int n)
	{
		int result = INT_MIN;
		int product = 1;
		int product_minus = 0;
		int i = 0;
		int j = n - 1;
		while (i < n)
		{
			product *= A[i];
			result = max(result, product);
			if (product < 0)
			{
				if (product_minus)
				{
					product *= product_minus;
					product_minus = 0;
					result = max(result, product);
				}
				else
				{
					product_minus = product;
					product = 1;
				}
			}
			if (product < 1)
			{
				product = 1;
				product_minus = 0;
			}
			i++;
		}

		product = 1;
		product_minus = 0;
		while (j >= 0)
		{
			product *= A[j];
			result = max(result, product);
			if (product < 0)
			{
				if (product_minus)
				{
					product *= product_minus;
					product_minus = 0;
					result = max(result, product);
				}
				else
				{
					product_minus = product;
					product = 1;
				}
			}
			if (product < 1)
			{
				product = 1;
				product_minus = 0;
			}
			j--;
		}

		return result;
	}

	int maxProduct3(int A[], int n)
	{
		int result = A[0];
		int largest_product = A[0];
		int smallest_product = A[0];
		int i = 1;
		int product = A[0];
		while (i < n)
		{

			int tmp_largest = max(max(largest_product * A[i], A[i]), smallest_product * A[i]);
			int tmp_smallest = min(min(largest_product * A[i], A[i]), smallest_product * A[i]);
			largest_product = tmp_largest;
			smallest_product = tmp_smallest;
			result = max(result, largest_product);
			i++;
		}
		return result;
	}
private:

	int getRangeProduct(int A[], int i, int j)
	{
		int product = 1;
		while (i <= j)
		{
			product *= A[i++];
		}
		return product;
	}
};

int main()
{
	int A[] = {2, 3, -2, 4, 3, -1, -2, -5, 19, 3};
	//int A[] = { -2, 0, -1 };
	//int A[] = { 2, -5, -2, -4, 3 };
	//int A[] = { -5, -2, -4, 3 };
	//int A[] = {-4, -3, -2};

	Solution s;
	cout << s.maxProduct(A, sizeof(A) / sizeof(int)) << endl;
	cout << s.maxProduct2(A, sizeof(A) / sizeof(int)) << endl;
	cout << s.maxProduct3(A, sizeof(A) / sizeof(int)) << endl;
	return 0;
}
