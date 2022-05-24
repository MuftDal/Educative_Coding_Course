#include <bits/stdc++.h>

using namespace std;

int findLength(const vector<int> &arr, int k) {
    int maxOnes = 0, start = 0, maxLength = 0;
    for(int end = 0; end<arr.size(); end++) {
        
        if(arr[end] == 1)
            maxOnes++;
        if(end - start + 1 - maxOnes > k) {
            if(arr[start] == 1)
                maxOnes--;
            start++;
        }
        maxLength = max(maxLength,end - start + 1);
    }
    
    return maxLength;
}

int main()
{
    cout<<findLength({0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1}, 3);

    return 0;
}
