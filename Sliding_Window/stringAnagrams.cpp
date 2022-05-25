#include <bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s1, string s2) {
        // if(s1.length() > s2.length())
        //     return {};
        unordered_map<char,int> pat;
        for(auto ch : s1)
            pat[ch]++;
        
        int matching = 0, start = 0;
        vector<int> result;

        for(int end = 0; end < s2.length(); end++) {
            char r = s2[end];
            if(pat.find(r) != pat.end()) {
               pat[r]--;
               if(pat[r] == 0)
                matching++;
            }
            
            if(matching == (int)pat.size())
                result.push_back(start);
                
            if(end >= s1.length() - 1) {
                char l = s2[start++];
                if(pat.find(l) != pat.end()) {
                    if(pat[l] == 0)
                        matching--;
                    pat[l]++;
                }
            }
        }
        return result;
    }

int main()
{
    auto res = findAnagrams("abc","abbcabc");
    for(auto num : res) {
        cout<<num<<" ";
    }

    return 0;
}
