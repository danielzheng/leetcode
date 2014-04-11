class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if (prices.empty())
		{
			return 0;
		}
		buildCurrentMaxPrices(prices);
		int index = 0;
		for (auto it = prices.begin(); it != prices.end(); ++it)
		{
			currentMaxPrices[index] = currentMaxPrices[index] - *it;
			index++;
		}
		return *max_element(currentMaxPrices.begin(), currentMaxPrices.end());
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
	vector<int> currentMaxPrices;
};