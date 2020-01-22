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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        if (head == NULL){ //check if there is a head node.
            return NULL;
        }
        while(curr->next != NULL) 
        {
            if (curr->next->val == curr->val) //check if the next node has the same value of current
            {
                if (curr->next->next != NULL){ // if there is at least three nodes
                    curr->next = curr->next->next; //let current->next be the one right after.
                }
                else if (curr->next->next == NULL){ //if there isnt at least 3 nodes(meaning theres only 2)
                    curr->next = NULL; //set next to null
                    break; //break out the loop
                }
            }
            else //if the next node is not the same, go to next node
            {
            curr = curr->next;
            }
        }
        return head;
    }
};