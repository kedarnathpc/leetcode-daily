int countStudents(vector<int> &arr, int m, int pages){
    int students = 1;
    long long pagesStudents = 0;

    for(auto &i : arr) {
        if(pagesStudents + i <= pages)
            pagesStudents += i;
        else {
            students++;
            pagesStudents = i;
        }
    }

    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m > n)
        return -1;
    
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high){
        int mid = low + (high - low)/2;
        if(countStudents(arr, m, mid) > m)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}
