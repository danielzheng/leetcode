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
    bool isPalindrome(ListNode* head) {
	head1 = head;
	ListNode *ptr1 = head;
	ListNode *ptr2 = head;
	while(ptr2 != NULL && ptr2->next != NULL)
	{
	    ptr1 = ptr1->next;
	    ptr2 = ptr2->next->next;
	}
	head2 = reverseLinkedList(ptr1);

	while(head2)
	{
	    if (head1->val != head2->val)
	    {
		return false;
	    }
	    head1 = head1->next;
	    head2 = head2->next;
	}
	return true;
    }
private:
    ListNode* reverseLinkedList(ListNode* head)
    {
	if (head == NULL)
	{
	    return NULL;
	}
	ListNode * pre = head;
	ListNode * cur = head->next;
	ListNode * tmp = NULL;
	pre->next = NULL;

	while (cur)
	{
	    tmp = cur->next;
	    cur->next = pre;	
	    pre = cur;
	    cur = tmp;
	}
	return pre;
    }
    ListNode *head1;
    ListNode *head2;
};

int main()
{
    ListNode n5(5);
    ListNode n4(4);
    ListNode n3(3);
    ListNode n2(2);
    ListNode n1(1);

    ListNode N5(5);
    ListNode N4(4);
    ListNode N3(3);
    ListNode N2(2);
    ListNode N1(1);

    n5.next = &n4;
    n4.next = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = &N1;

    N1.next = &N2;
    N2.next = &N3;
    N3.next = &N4;
    N4.next = &N5;

//    ListNode n1(1);
//    ListNode n2(2);
//
//    n1.next = &n2;

    Solution s;
    cout << boolalpha << s.isPalindrome(&n3) << endl;

    return 0;
}
