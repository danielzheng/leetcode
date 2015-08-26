#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//return recursiveReverseList(head);    
		return iterativeReverseList(head);
	}
private:
	ListNode* iterativeReverseList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode * pre = head;
		ListNode * cur = head->next;
		ListNode * tmp = NULL;
		head->next = NULL;
		while (cur)
		{
			tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}

	ListNode* recursiveReverseList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode * newHead = recursiveReverseList(head->next);
		head->next->next = head;
		head->next = NULL;

		return newHead;
	}
};

int main()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	Solution s;
	auto l = s.reverseList(&n1);

	while (l)
	{
		cout << l->val << " " << endl;
		l = l->next;
	}
	cout << endl;


	return 0;	
}
