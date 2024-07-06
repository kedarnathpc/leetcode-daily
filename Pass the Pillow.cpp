class Solution {
public:
    int passThePillow(int n, int time) {
        bool right = true;
        int i = 1;

        while (time--) {
            if (i == n) {
                right = false;
            }
            if (i == 1) {
                right = true;
            }
            if (right) {
                i++;
            }
            else {
                i--;
            }
        }

        return i;
    }
};
