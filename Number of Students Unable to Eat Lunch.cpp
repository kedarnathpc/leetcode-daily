class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int i = 0, j = 0;
        for(auto &i : students) 
            q.push(i);
            
        int unchanged = 0; 

        while (i < sandwiches.size() && unchanged < q.size()) {
            if (q.front() == sandwiches[i]) {
                q.pop();
                i++;
                unchanged = 0; 
            } else {
                q.push(q.front());
                q.pop();
                unchanged++; 
            }
        }

        return q.size();
    }
};
