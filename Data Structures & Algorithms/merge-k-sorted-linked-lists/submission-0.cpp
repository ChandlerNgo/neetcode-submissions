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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>, greater<int>> pq;

        for(int i = 0; i < lists.size(); i++){
            ListNode* cur = lists[i];
            while(cur != nullptr){
                pq.push(cur->val);
                cur = cur->next;
            }
        }

        ListNode* head = new ListNode();
        ListNode* cur = head;
        while(!pq.empty()){
            ListNode* temp = new ListNode(pq.top());
            cur->next = temp;
            cur = cur->next;
            pq.pop();
        }
        return head->next;
    }
};