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
	ListNode *insertionSortList(ListNode *head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode tempHead(0);
		tempHead.next = head;
		ListNode * prevLi = &tempHead;

		for (ListNode * li = head; li != NULL; li = li->next)
		{
			ListNode * prevLj = li;
			for (ListNode * lj = li->next; lj != NULL; lj = lj->next)
			{
				if (lj->val < li->val)
				{
					insertListNode(prevLi, prevLj);
					li = lj;
				}
				prevLj = lj;
			}
			prevLi = li;
		}
		return tempHead.next;
	}
	void insertListNode(ListNode * prev1, ListNode * prev2)
	{
		ListNode * temp = prev2->next;
		prev2->next = prev2->next->next;
		temp->next = prev1->next;
		prev1->next = temp;
	}
};