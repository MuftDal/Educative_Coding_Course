#include <bits/stdc++.h>

using namespace std;

int findLength(const vector<char> &arr) {
    int maxLength = 0, start = 0;
    unordered_map<char,int> fruits;
    for(int end = 0; end<arr.size(); end++) {
        fruits[arr[end]]++;
        
        while((int)fruits.size() > 2) {
            fruits[arr[start]]--;
            if(fruits[arr[start]] == 0)
                fruits.erase(arr[start]);
            start++;
        }
        maxLength = max(maxLength,end - start + 1);
    }
    
    return maxLength;
}

int main()
{
    cout<<findLength({'A', 'B', 'C', 'B', 'B', 'C'});

    return 0;
}
