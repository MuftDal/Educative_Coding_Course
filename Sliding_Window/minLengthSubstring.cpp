#include <bits/stdc++.h>

using namespace std;

string findSubstring(const string &pattern, const string &str) {
    
        unordered_map<char,int> pat;
        for(auto ch : pattern)
            pat[ch]++;
        
        int matching = 0, start = 0, strStart = 0, minLength = str.length() + 1;

        for(int end = 0; end < str.length(); end++) {
            char r = str[end];
            if(pat.find(r) != pat.end()) {
               pat[r]--;
               if(pat[r] >= 0)
                matching++;
            }
            
            while(matching == pattern.length()) {
                if(minLength > end - start + 1) {
                    minLength = end - start + 1;
                    strStart = start;
                }
                char l = str[start++];
                if(pat.find(l) != pat.end()) {
                    if(pat[l] == 0)
                        matching--;
                    pat[l]++;
                }
            }
        }
        
        return minLength > str.length() ? "" : str.substr(strStart,minLength);
    }

int main()
{
    cout<<findSubstring("abc","aabdec");

    return 0;
}
