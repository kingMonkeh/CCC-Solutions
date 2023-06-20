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
        ListNode* root = new ListNode;
        ListNode* conductor = root;
        int carryover = 0;
        while (l1 != nullptr || l2 != nullptr){
            conductor->val += carryover;
            if (l1 != nullptr){
                conductor->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr){
                conductor->val += l2->val;
                l2 = l2->next;
            }
            carryover = conductor->val / 10;
            if (conductor->val >= 10){
                conductor->val %= 10;
            }
            if (l1 != nullptr || l2 != nullptr){
                conductor->next = new ListNode;
                conductor = conductor->next;
            }
        }
        if (carryover > 0){
            conductor->next = new ListNode;
            conductor = conductor->next;
            conductor->val = carryover;
        }
        return root;
    }
};