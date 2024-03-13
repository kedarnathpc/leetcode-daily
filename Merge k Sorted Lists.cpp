class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for (auto &i : lists) {
            if (i)
                pq.push({i->val, i});
        }

        ListNode* temp = new ListNode(-1);
        ListNode* curr = temp;

        while (!pq.empty()) {
            auto i = pq.top();
            pq.pop();

            if (i.second->next)
                pq.push({i.second->next->val, i.second->next});
            curr->next = i.second;
            curr = curr->next;
        }

        return temp->next;
    }
};
