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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        ListNode res(0); //dummy head 
        ListNode* newList = &res; //newList will have a dummy head 
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val)
            {
                newList->next = l1; //append the according values to the next part of the list
                l1 = l1->next; //iterate 
            }
            else
            {
                newList->next = l2;
                l2 = l2->next; //iterate
            }
            newList = newList->next; //go to the end of the newList
        }
        //if we break out the while loop,either theres more l1 left, l2 left or none, plan accordingly.
        if (l1) 
        {
            newList->next = l1;
        }
        else if (l2)
        {
            newList->next = l2;
        }
        return res.next; //return everything after dummy head
    }
};