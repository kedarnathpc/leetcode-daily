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
    ListNode* reverse(ListNode *mid){
        ListNode *prev = NULL;
        ListNode *nxt = NULL;
        while(mid){
            nxt = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nxt;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return 1;
        ListNode *temp = head;
        ListNode *mid = head;
        ListNode *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            mid = mid->next;
            fast = fast->next->next;
        }
        mid->next = reverse(mid->next);
        mid = mid->next;
        while(mid){
            if(temp->val != mid->val) return 0;
            mid = mid->next;
            temp = temp->next;
        }
        return 1;
    }
};
