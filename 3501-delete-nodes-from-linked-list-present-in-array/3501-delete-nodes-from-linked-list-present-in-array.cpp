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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin() , nums.end());
        while(head != nullptr && st.count(head->val) > 0){
            ListNode* temp = head;
            head = head->next;
            // delete temp;
        }

        if(head == nullptr){
            return nullptr;
        }

        ListNode* curr = head;

        while(curr->next != nullptr){
            if(st.count(curr->next->val) > 0){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                // delete temp;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
        
    }
};