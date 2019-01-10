#include <iostream>
using namespace std;



/* Definition for singly-linked list. */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* result_p;
        ListNode* current_node;

        ListNode ln(0);
        result_p = &ln;
        current_node = &ln;
        
        ListNode* new_node_p;
        while(l1 || l2 || carry)
		{

			int sum = 0;
			
            sum = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val: 0);
            if (carry) sum++;
            
            l1 = l1? l1->next: NULL;
            l2 = l2? l2->next: NULL;

            carry = (sum >= 10);
            
            
            current_node->next = new ListNode(sum % 10);
            current_node = current_node->next;
            int i = 2;
            int_p = &i;
    	}
    	// cout << "starting node: " << result_p->val << endl;
    	return ln.next;
    }
};

void main()
{
	ListNode lnA1(1);
	ListNode lnA2(2);
	ListNode lnA3(3);
	ListNode lnB1(1);
	ListNode lnB2(2);
	ListNode lnB3(3);
	lnA1.next = &lnA2;
	lnA2.next = &lnA3;
	lnB1.next = &lnB2;
	lnB2.next = &lnB3;

	ListNode* l1 = &lnA1;
	ListNode* l2 = &lnB1;

	Solution sol;
	ListNode* result = sol.addTwoNumbers(l1, l2);
	int out_step = 0;
	// while (result)
	// {
	// 	cout << "out step :" << out_step << endl;
	// 	cout << result->val <<endl;
	// 	result = result->next;
	// 	out_step ++;
	// }
	
	

}