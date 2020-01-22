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
    void deleteNode(ListNode* node) {
        //delete a node except for the tail, you can only start out 
		//with the node youre given, 
        //meaning you dont know/care for what is before it, cant use the traditional method unfortunately of a dummy node. 
        //brute method is just to write over the value.
        if (node->next == NULL || node == NULL) { //check to see if its the tail just as a precaution and checks if the next item is the tail.
            return;
        }
        node->val = node->next->val; //set the value of the node to the next node
        node->next = node->next->next; //set the value of the node after to its suceeding node value.
        
    }
};