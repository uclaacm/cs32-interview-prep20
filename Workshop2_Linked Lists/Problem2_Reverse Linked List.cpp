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
    ListNode* reverseList(ListNode* head) {
       //since this is singly linked, only the next node is provided
        if (head == NULL) //check if the list is empty
        {
            return NULL;
        }
        ListNode* newHead = NULL; 
        ListNode* curr = head; 
        while (curr != NULL){ //while traversing the list 
            ListNode* temp = curr->next; //we need a temporary node to store the next 
            //as a singly linked list, we dont know the prev after saving to new
            curr->next = newHead; //the new current will now point to its "prev"
            newHead = curr;
            curr = temp; //move on to the next node
        }
        return newHead; //return new "head", last item head
    }
};