bool solve(int i, int k, int sum, vector<int> &arr){
    if(sum == k)
        return true;
    if(i >= arr.size() or sum > k)
        return false;
    
    bool flag1 = solve(i + 1, k, sum + arr[i], arr); 
        if(flag1)
            return true;
    bool flag2 = solve(i + 1, k, sum, arr);
        if(flag2)
            return true; 

    return false; 
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    return solve(0, k, 0, a);
}
