class Solution {
public:
    int singleNumber(int A[], int n) {
        int high = 0;
		int low = 0;
		int not_three = 0;
		int curr_elem = 0;

		for (int i = 0; i < n; i++)
		{
			curr_elem = A[i];
			high |= low & A[i];
			low = low ^ A[i];
			not_three = ~(high & low);
			low = low & not_three;
			high = high & not_three;
		}
		return low ^ high;
    }
};