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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);

        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // reaching the nth node from the start
        for(int i=0  ; i<=n ; i++){
            first = first->next;
        }
        
        // reaching the nth node from the end, since now the difference betwern the forst and the second node is n
        // so when first is at the last, then secon would be nth from the last.
        while(first != nullptr){
            first = first->next;
            second = second->next;
        }

        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        return dummy->next;

        
    }
};