/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head)
		{
			return NULL;
		}
		RandomListNode * currentNode = head;
		while (currentNode)
		{
			RandomListNode * newNode = new RandomListNode(currentNode->label);
			newNode->next = currentNode->next;
			currentNode->next = newNode;
			currentNode = currentNode->next->next;
		}

		currentNode = head;
		RandomListNode * nextNode = currentNode->next;
		while (currentNode)
		{
			if (currentNode->random)
			{
				nextNode->random = currentNode->random->next;
			}
			currentNode = currentNode->next->next;
			if (currentNode)
			{
				nextNode = currentNode->next;
			}
		}

		RandomListNode * newHead = head->next;
		currentNode = head;
		nextNode = currentNode->next;
		while (currentNode)
		{
			currentNode->next = currentNode->next->next;
			if (nextNode->next)
			{
				nextNode->next = nextNode->next->next;
			}

			currentNode = currentNode->next;
			nextNode = nextNode->next;
		}

		return newHead;
	}
};