#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
    	si_push.push(x);    
    }

    // Removes the element from in front of queue.
    void pop(void) {
       if (si_pop.empty())
	   {
		   while (!si_push.empty())
		   {
			   si_pop.push(si_push.top());
			   si_push.pop();
		   }
	   }
       si_pop.pop(); 
    }

    // Get the front element.
    int peek(void) {
       if (si_pop.empty())
	   {
		   while (!si_push.empty())
		   {
			   si_pop.push(si_push.top());
			   si_push.pop();
		   }
	   }
       return si_pop.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
    	return si_push.empty() && si_pop.empty();    
    }
private:
	stack<int> si_push;
	stack<int> si_pop;
};

int main()
{
	Queue Q;
	for (int i = 0; i < 10; i++)
	{
		Q.push(i);
	}
	while (!Q.empty())
	{
		cout << Q.peek() << endl;
		Q.pop();
	}

	return 0;
}
