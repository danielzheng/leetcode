class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> ss;
		while(!tokens.empty())
		{
			if (isOperator(*tokens.begin()))
			{
				int op1 = ss.top();
				ss.pop();
				int op2 = ss.top();
				ss.pop();
				int tmpValue = operation(op2, op1, *tokens.begin());
				ss.push(tmpValue);
			}
			else
			{
				int num = atoi((*tokens.begin()).c_str());
				ss.push(num);
			}
			tokens.erase(tokens.begin());
		}
		return ss.top(); 
    }
    
private:
	int operation(int num1, int num2, const string& operatorChar)
	{
		switch (*operatorChar.begin())
		{
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2;
		case '/':
			assert(num2);
			return num1 / num2;
		default:
			exit(1);
		}
	}

	bool isOperator(const string& operatorChar)
	{
		if (operatorChar == "+" ||operatorChar == "-" || operatorChar == "*" || operatorChar == "/")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
