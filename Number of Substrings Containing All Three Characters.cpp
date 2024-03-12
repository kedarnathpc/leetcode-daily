class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length(), i = 0, j = 0, cnt = 0;
        vector<int> arr(3,0);
    
        while(j < n){
            arr[s[j]-'a']++;
            while(arr[0] >= 1 and arr[1] >= 1 and arr[2] >= 1){
                cnt += (n-j);
                arr[s[i]-'a']--;
                i++;
            }
            j++;
        }

        return cnt;
    }
};
