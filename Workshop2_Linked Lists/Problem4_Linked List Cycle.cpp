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
    bool hasCycle(ListNode *head) {
    
        ListNode* ptr1 = head; //want both ptrs to start at the same place
        ListNode* ptr2 = head;

        while(ptr2 != NULL && ptr2->next != NULL){ //this is the tortoise and hare algorithm
            ptr1 = ptr1->next; 
            ptr2 = (ptr2->next)->next; //ptr2 is always ahead of ptr1, and if ptr2 ever 
            if(ptr1 == ptr2) //equals ptr1, then there is a cycle
            {
                return true; 
            }
        }
        return false; //if there is no cycle, ptr2 exits the while loop and returns false,
		//no cycle in this linked list
        
    }
};