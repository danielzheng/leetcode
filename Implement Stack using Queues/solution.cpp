#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
	   auxiliary.push(x);	
	   while (!master.empty())
	   {
		   auxiliary.push(master.front());
		   master.pop();
	   }
	   while (!auxiliary.empty())
	   {
		   master.push(auxiliary.front());
		   auxiliary.pop();
	   }
    }

    // Removes the element on top of the stack.
    void pop() {
        master.pop();
    }

    // Get the top element.
    int top() {
       return master.front(); 
    }

    // Return whether the stack is empty.
    bool empty() {
    	return master.empty() && auxiliary.empty();    
    }
private:
	queue<int> master;
	queue<int> auxiliary;
};

int main()
{
	Stack s;
	for (int i = 0; i < 10; i++)
	{
		s.push(i);
	}

	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}
