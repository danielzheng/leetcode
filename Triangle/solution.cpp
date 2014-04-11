class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.empty())
		{
			return 0;
		}
		buildMinSum(triangle);
		return triangle[0][0];
    }
private:
	void buildMinSum(vector<vector<int> > &triangle)
	{
		int level = triangle.size();
		for (int i = level - 1; i >= 1; i--)
		{
			for (int j = 0; j < triangle[i].size() - 1; j++)
			{
				triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1]);
			}
		}
	}
};