class Solution {
public:
	enum OPERATION
	{
		WAITANDSEE,
		BUY,
		SELL
	};
	enum STATUS
	{
		HOLD,
		EMPTY
	};
	//use index as day num 
    int maxProfit(vector<int> &prices) {
		if (prices.empty())
		{
			return 0;
		}
		int daysNum = prices.size();
		records.resize(daysNum);
		STATUS s = EMPTY;
		
		for (int i = 0; i < (daysNum - 1); i++)
		{
			records[i] = WAITANDSEE;
			if (prices[i] < prices[i + 1])
			{
				if (s == EMPTY)
				{
					s = HOLD;
					records[i] = BUY;
				}
			}
			else if(prices[i] > prices[i + 1])
			{
				if (s == HOLD)
				{
					s = EMPTY;
					records[i] = SELL;
				}

			}
		}
		//for the last day
		if (s == HOLD)
		{
			auto record = records.end() - 1;
			*record = SELL;
			s = EMPTY;
		}
		//go througe operation records and calculate sum 
		int buyPrice = 0;
		int sellPrice = 0;
		int sumProfits = 0;
		for (int i = 0; i < daysNum; i++)
		{
			switch (records[i])
			{
			case WAITANDSEE:
				break;
			case SELL:
				sellPrice = prices[i];
				sumProfits += (sellPrice - buyPrice);
				break;
			case BUY:
				buyPrice = prices[i];
				break;
			default:
				exit(1);
			}
		}
		return sumProfits;
    }
private:
	vector<OPERATION> records;
};