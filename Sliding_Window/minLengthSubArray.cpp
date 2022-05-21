#include <bits/stdc++.h>

using namespace std;

int findMinSubArray(int s, const vector<int> &arr) {
    int minLength = INT_MAX, sum = 0, start = 0;
    for(int end = 0; end<arr.size();end++) {
        sum += arr[end];
        while(sum >= s) {
            minLength = min(minLength,end - start + 1);
            sum -= arr[start];
            start++;
        }
    }
    
    return minLength == numeric_limits<int>::max()? 0 : minLength;
}

int main()
{
    cout<<findMinSubArray(8, vector<int> {3, 4, 1, 1, 6});

    return 0;
}
