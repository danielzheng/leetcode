class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.empty())
		{
			return 0;
		}
		buildProfitArray(prices);
		int maxValueOnce = maxProfitDown[0];
		int maxValueTwice = 0;
		for (int i = 1; i < prices.size() - 1; i++)
		{
			maxValueTwice = max(maxValueTwice, maxProfitUp[i] + maxProfitDown[i + 1]);
		}
		return max(maxValueOnce, maxValueTwice);
	}

private:
	void buildCurrentMaxPrices(vector<int>& prices)
	{
		if (prices.empty())
		{
			return;
		}
		currentMaxPrices.resize(prices.size());
		int maxPrices = *(prices.end() - 1);
		int index = currentMaxPrices.size() - 1;
		for (; index >= 0; index--)
		{
			if (prices[index] > maxPrices)
			{
				maxPrices = prices[index];
			}
			currentMaxPrices[index] = maxPrices;
		}
	}

	void buildCurrentMinPrices(vector<int>& prices)
	{
		if (prices.empty())
		{
			return;
		}
		currentMinPrices.resize(prices.size());
		int minPrices = *prices.begin();
		for (int index = 0; index < prices.size(); index++)
		{
			if (prices[index] < minPrices)
			{
				minPrices = prices[index];
			}
			currentMinPrices[index] = minPrices;
		}
	}
	void buildProfitArray(vector<int>& prices)
	{
		buildCurrentMaxPrices(prices);
		buildCurrentMinPrices(prices);
		maxProfitUp.resize(prices.size());
		maxProfitDown.resize(prices.size());
		for (int i = 0; i < prices.size(); i++)
		{
			maxProfitUp[i] = prices[i] - currentMinPrices[i];
			maxProfitDown[i] = currentMaxPrices[i] - prices[i];
		}

		for (int i = 1; i < prices.size(); i++)
		{
			maxProfitUp[i] = max(maxProfitUp[i - 1], maxProfitUp[i]);
		}
		for (int i = prices.size() - 2; i >= 0; i--)
		{
			maxProfitDown[i] = max(maxProfitDown[i], maxProfitDown[i + 1]);
		}
	}
	vector<int> currentMaxPrices;
	vector<int> currentMinPrices;
	vector<int> maxProfitUp;
	vector<int> maxProfitDown;
};