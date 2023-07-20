#include <bits/stdc++.h> 
long long int binarypush(vector<long long int>& sorted, long long int target){
    long long int l = 0;
    long long int h = sorted.size()-1;
    while(l <= h){
        long long int mid = l + (h - l)/2;

        if(sorted[mid] > target){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    sorted.insert(sorted.begin()+h+1, target);
    return h+1;
}
long long getInversions(long long *arr, int n){
    vector<long long int> sorted;
    sorted.push_back(arr[0]);
    long long int cnt = 0;
    for(long long int i = 1; i < n; ++i){
        long long int pos = binarypush(sorted, arr[i]);
        cnt += sorted.size() - pos - 1;
    }

    return cnt;
}

