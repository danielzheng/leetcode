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
    ListNode *detectCycle(ListNode *head) {
		if (head == NULL)
		{
			return NULL;
		}
		ListNode * p1 = head;
		ListNode * p2 = head;
		int counter = 0;
		bool hasCycle = false;
		while (p1 && p2 && p1->next && p2->next)
		{
			counter++;
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == p2)
			{
				if (p1 == head)
				{
					return head;
				}
				else
				{
					hasCycle = true;
					break;
				}
			}
		}

		if (hasCycle)
		{
			p1 = p2 = head;
			while (counter > 0)
			{
				p2 = p2->next;
				counter--;
			}
			while (p1 != p2)
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			return p1;
		}
		else
		{
			return NULL;
		}
    }
};