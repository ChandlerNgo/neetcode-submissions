/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* curNode = head;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1 != nullptr || l2 != nullptr){
            if(l1 != nullptr && l2 != nullptr){
                if(l1->val < l2->val){
                    curNode->next = l1; // puts node in list
                    l1 = l1->next; // moves to next
                }else{
                    curNode->next = l2; // puts node in list
                    l2 = l2->next; // moves to next
                }
            }else if(l1 != nullptr){
                curNode->next = l1; // puts node in list
                l1 = l1->next; // moves to next
            }else if(l2 != nullptr){
                curNode->next = l2; // puts node in list
                l2 = l2->next; // moves to next
            }
            curNode = curNode->next; // moves to next position
        }
        return head->next;
    }
};
