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
    bool hasCycle(ListNode* head) {
        // ListNode* slow = head;
        // ListNode* fast = head;

        // while(slow != fast){
        //     if(fast->next == nullptr || fast->next->next == nullptr){
        //         return false;
        //     }

        //     slow = slow->next;
        //     fast = fast->next->next;
        // }

        // int index = 0;

        int count = 0;
        ListNode* cur = head;
        while(count < 1002 && cur != nullptr){
            cur = cur->next;
            count += 1;
        }

        if(count > 1000){
            return true;
        }else{
            return false;
        }
    }
};
