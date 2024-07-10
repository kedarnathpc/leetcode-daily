class Solution {
public:
    int minOperations(vector<string>& logs) {
        int pos = 0;

        for (auto path : logs) {
            if (path == "../") {
                if (pos == 0) {
                    continue;
                }
                else {
                    pos--;
                }
            }
            else if (path == "./") {
                continue;
            }
            else {
                pos++;
            }
        }

        return pos;
    }
};
