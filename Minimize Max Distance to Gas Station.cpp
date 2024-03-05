#include <bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	int n = arr.size();
	vector<int> sections(n-1, 0);
	priority_queue<pair<long double,int>> pq;

	for(int i = 0; i < n-1; ++i)
		pq.push({arr[i+1] - arr[i], i});

	for(int i = 1; i <= k; ++i) {
		auto it = pq.top();
		pq.pop();
		int secInd = it.second;
		sections[secInd]++;

		long double iniDiff = arr[secInd + 1] - arr[secInd];
		long double newDiff = iniDiff / (long double)(sections[secInd] + 1);

		pq.push({newDiff, secInd});
	}

	return pq.top().first;
}
