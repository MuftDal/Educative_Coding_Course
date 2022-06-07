#include <bits/stdc++.h>

using namespace std;

int RemoveDuplicates(vector<int> &arr) {
    int n = arr.size(), nondup = 1;
    for(int i = 1; i<n-1; i++) {
        if(arr[nondup - 1] != arr[i]) {
            arr[nondup] = arr[i];
            nondup++;
        }
    }
    return nondup;
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
    cout<<RemoveDuplicates(arr);
    return 0;
}
