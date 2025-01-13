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
    ListNode* solve(ListNode* prev,ListNode* curr){
        if(curr->next==NULL){
            curr->next=prev;
            return curr;
        }
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        return solve(curr,next);
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        return solve(NULL,head);
    }
};