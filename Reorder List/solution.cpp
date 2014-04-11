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
	void reorderList(ListNode *head) {
		if (!head || !head->next || !head->next->next)
		{
			return;
		}
		ListNode pseudoHead(0);
		pseudoHead.next = head;
		ListNode * l1 = &pseudoHead;
		ListNode * l2 = &pseudoHead;
		while (l2 && l2->next)
		{
			l1 = l1->next;
			l2 = l2->next->next;
		}
		l2 = l1->next;
		l1->next = NULL;
		l1 = head;
		l2 = reverseList(l2);
		mergeTwoList(l1, l2);
	}
	ListNode * reverseList(ListNode *head)
	{
		if (!head || !head->next)
		{
			return head;
		}
		ListNode * newHead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return newHead;
	}
	void mergeTwoList(ListNode *l1, ListNode *l2)
	{
		while (l1 && l2)
		{
			ListNode * tempL2Next = l2->next;
			l2->next = l1->next;
			l1->next = l2;
			l2 = tempL2Next;
			l1 = l1->next->next;
		}
	}
};