bool canPlace(vector<int> &stalls, int dist, int k){
    int cows = 1, last = stalls[0];
    
    for(int i = 1; i < stalls.size(); ++i){
        if(stalls[i] - last >= dist){
            cows++;
            last = stalls[i];
        }
        if(cows >= k)
            return true;
    }
    
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[stalls.size()-1] - stalls[0];

    while(low <= high){
        int mid = low + (high - low)/2;
        if(canPlace(stalls, mid, k))
            low = mid + 1;
        else 
            high = mid - 1;
    }

    return high;
}
