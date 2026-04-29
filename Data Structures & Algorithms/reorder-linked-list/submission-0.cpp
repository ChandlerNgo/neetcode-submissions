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
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        int n = 0;
        while(cur != nullptr){
            n += 1;
            cur = cur->next;
        }

        if(n <= 2){
            return;
        }

        ListNode* t = head;

        for(int i = 0; i < ((n/2) - 1); i++){
            t = t->next;
        }

        cur = t->next;
        t->next = nullptr;
        
        ListNode* prev = nullptr;
        while(cur != nullptr){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        ListNode* left = head;
        ListNode* right = prev;
        ListNode* newLeft = nullptr;
        ListNode* newRight = nullptr;

        while(left != nullptr && right != nullptr){
            newLeft = left->next;
            newRight = right->next;
            left->next = right;

            if(newLeft == nullptr){
                break;
            }
            right->next = newLeft;
            left = newLeft;
            right = newRight;
        }
    }
};