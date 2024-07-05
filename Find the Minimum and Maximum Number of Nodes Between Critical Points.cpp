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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX, maxDistance = -1, dist = 0;
        int prev = head->val;
        ListNode* curr = head->next;
        vector<int> points;

        while (curr->next) {
            // local maxima
            if (curr->next && curr->val > prev && curr->val > curr->next->val) {
                points.push_back(dist);
            }
            // local minima
            else if (curr->next && curr->val < prev && curr->val < curr->next->val) {
                points.push_back(dist);
            }
            prev = curr->val;
            curr = curr->next;
            dist++;
        }

        if (dist < 2 || points.size() < 2)
            return {-1, maxDistance};

        for (int i = 0; i < points.size()-1; ++i) {
            minDistance = min(minDistance, points[i+1] - points[i]);
        }

        maxDistance = points.back() - points[0];

        return {minDistance, maxDistance};
    }
};
