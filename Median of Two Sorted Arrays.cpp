class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0, n = (n1 + n2);
        int ind2 = n/2;
        int ind1 = ind2 - 1;
        int ind1el = INT_MIN, ind2el = INT_MIN;
        int cnt = 0;

        while(i < n1 and j < n2){
            if(nums1[i] < nums2[j]){
                if(cnt == ind1)
                    ind1el = nums1[i];
                if(cnt == ind2)
                    ind2el = nums1[i];
                cnt++;
                i++;
            }
            else {
                if(cnt == ind1)
                    ind1el = nums2[j];
                if(cnt == ind2)
                    ind2el = nums2[j];
                cnt++;
                j++;
            }
        }
        
        while(i < n1){
            if(cnt == ind1)
                ind1el = nums1[i];
            if(cnt == ind2)
                ind2el = nums1[i];
            cnt++;
            i++;
        }

        while(j < n2){
            if(cnt == ind1)
                ind1el = nums2[j];
            if(cnt == ind2)
                ind2el = nums2[j];
            cnt++;
            j++;
        }

        return n&1 ? (double)ind2el : (double)((double)(ind1el + ind2el))/2.0;
    }
};
