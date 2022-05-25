#include <bits/stdc++.h>

using namespace std;

bool findPermutation(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        vector<int> pat(26,0);
        vector<int> win(26,0);
        for(int i = 0; i<s1.length(); i++) {
            pat[s1[i] - 'a']++;
            win[s2[i] - 'a']++;
        }
        
        int matching = 0;
        for(int i = 0; i<26; i++)
            if(pat[i] == win[i])
                matching++;
        for(int i = 0; i<s2.length() - s1.length(); i++) {
            int r = s2[i + s1.length()] - 'a', l = s2[i] - 'a';
            if(matching == 26)
                return true;
            win[r]++;
            if(win[r] == pat[r])
                matching++;
            else if(win[r] == pat[r] + 1)
                matching--;
            win[l]--;
            if(win[l] == pat[l])
                matching++;
            else if(win[l] == pat[l] - 1)
                matching--;
        }
        return matching == 26;
    }

int main()
{
    cout<<findPermutation("bcdxabcdy","bcdyabcdx");

    return 0;
}
