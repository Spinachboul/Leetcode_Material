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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);

        ListNode* curr = dummyHead;

        int carry = 0;
        while(l1 != NULL || l2!= NULL || carry != 0){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            // carry will always be added to the sum
            int sum = x + y + carry;
            carry = sum / 10;
            // make a new node and set it to curr->next;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;

        }
        ListNode* res = dummyHead->next;
        return res;
        
    }
};