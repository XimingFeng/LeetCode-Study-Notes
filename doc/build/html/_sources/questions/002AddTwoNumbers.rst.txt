2. Add two numbers 
=======================

Lets write it down the example

 * (2 -> 2 -> 3)
 * (5 -> 6 -> 4)

seems like  we can use one loop to iterate through the two link list at the same time
but in case of different length of link lists, we need to check if node is Null each time when we jump to the next node

 * (2 -> 4 -> 3)
 * (5 -> 6 -> 4)

In the second situation when the sum of two digits is greater than 10, we just need the reminder of the sum and use a variable to carry digit 1 to the next 
node or nodes, lets call this variable carry.

 * (2 -> 2 -> 6)
 * (5 -> 6 -> 4)

In the third situation, when the we need to add new node even if we have reached the end of both linked list since the sum is of the last digits is more
than 10. So for the loop, we can add one more criteria to check the variable carry is true or false. So when we reach the end of both linked list, if check is true, we create a new node and add one to the value of the node. 

.. code-block:: c
	:linenos:

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

While debugging, I found I cannot just create a new node in the while loop without using "new" key word. 
You can see the note here 
:ref:`dynamic-allcation`