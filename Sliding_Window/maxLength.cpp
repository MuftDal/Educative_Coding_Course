#include <bits/stdc++.h>

using namespace std;

int findLength(int k, const string &str) {
    int maxLength = 0, start = 0;
    unordered_map<char,int> letters;
    for(int end = 0; end<str.length(); end++) {
        letters[str[end]]++;
        
        while((int)letters.size() > k) {
            letters[str[start]]--;
            if(letters[str[start]] == 0)
                letters.erase(str[start]);
            start++;
        }
        maxLength = max(maxLength,end - start + 1);
    }
    
    return maxLength;
}

int main()
{
    cout<<findLength(3, "cbbebi");

    return 0;
}
