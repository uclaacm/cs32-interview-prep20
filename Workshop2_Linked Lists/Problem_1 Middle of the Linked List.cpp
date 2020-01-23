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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL){ //check if there is a head for the linked list
            return NULL;
        }
        
        ListNode* current = head; //set to check the length of the linked list
        int length = 1; 
        
        while(current->next != NULL){
            length++; //increase the length for every successive linked list node
            current = current->next;
        }
        /*
        if node % 2 == 0 that means theres an even number of nodes, but since we want the second middle,
        then we can just add one from the truncated int(since if you divide an int and it results a float,
        the compiler will truncate the number)
        
        if node % s != 0 that means theres an odd number of nodes, which means we still want to add one to 
        the middle/
        */
        int middle = length / 2; 
        middle++;
        ListNode* traverse = head;
        
        while(node-- > 1){ //traverse until the middle node
            traverse = traverse->next;
        }
        
        return traverse; //return the middle node
    }
};