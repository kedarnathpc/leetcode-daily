class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> hash (1001, 0);
        vector<int> res;

        for (int i = 0; i < arr1.size(); ++i)
            hash[arr1[i]]++;

        for (int i = 0; i < arr2.size(); ++i)
            while (hash[arr2[i]]-- > 0)
                res.push_back(arr2[i]);

        for (int i = 0; i < hash.size(); ++i)
            while (hash[i]-- > 0)
                res.push_back(i);

        return res;  
    }
};
