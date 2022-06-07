#include <bits/stdc++.h>

using namespace std;

int RemoveDuplicates(vector<int> &arr) {
    int n = arr.size(), j = 0;
    for(int i = 0; i<n-1; i++) {
        if(arr[i] != arr[i+1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n-1];
    return j;
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
    cout<<RemoveDuplicates(arr);

    return 0;
}
