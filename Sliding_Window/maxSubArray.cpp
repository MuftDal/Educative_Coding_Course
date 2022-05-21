#include <bits/stdc++.h>

using namespace std;

int findMaxSubArray(int k, const vector<int> &arr) {
    int maxSum = 0, sum = 0, start = 0;
    for(int end = 0; end<arr.size();end++) {
        sum += arr[end];
        if(end >= k-1) {
            maxSum = max(maxSum,sum);
            sum -= arr[start];
            start++;
        }
    }
    
    return maxSum;
}

int main()
{
    cout<<findMaxSubArray(2, vector<int> {2, 3, 4, 1, 5});

    return 0;
}
