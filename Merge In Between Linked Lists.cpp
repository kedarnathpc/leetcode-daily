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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp = list1;
        ListNode *temp2 = list1;
        ListNode *temp3 = list2;

        for(int i = 0; i < a-1; ++i)
            temp = temp->next;
        
        for(int i = 0; i < b; ++i)
            temp2 = temp2->next;

        temp->next = list2;
        while(temp3->next){
            temp3 = temp3->next;
        }

        temp3->next = temp2->next;

        return list1;
    }
};
