/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (!head || !head->next)
		{
			return head;
		}
		//break list into 2 sub list
		ListNode * first = head;
		ListNode * second = head->next;
		while (second && second->next)
		{
			first = first->next;
			second = second->next->next;
		}
		second = first->next;
		first->next = NULL;
		return merge(sortList(head), sortList(second));
	}
	ListNode * merge(ListNode * first, ListNode * second)
	{
		ListNode head(0);
		ListNode * current = &head;
		while (first && second)
		{
			if (first->val > second->val)
			{
				current->next = second;
				second = second->next;
			}
			else
			{
				current->next = first;
				first = first->next;
			}
			current = current->next;
		}
		if (first)
		{
			current->next = first;
		}
		else if (second)
		{
			current->next = second;
		}
		return head.next;
	}
};
