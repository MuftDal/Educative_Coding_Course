#include <bits/stdc++.h>

using namespace std;

int findLength(const string &str) {
    int maxLength = 0, start = 0;
    unordered_map<char,int> letters;
    for(int end = 0; end<str.length(); end++) {
        
        if(letters.find(str[end]) != letters.end()) {
            start = max(start,letters[str[end]] + 1);
        }
        letters[str[end]] = end;
        maxLength = max(maxLength,end - start + 1);
    }
    
    return maxLength;
}

int main()
{
    cout<<findLength("abccdefg");

    return 0;
}
