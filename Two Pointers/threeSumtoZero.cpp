#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSumtoZero(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); i++) {
            if ((i>0) && (nums[i]==nums[i-1]))
            continue;
            int l = i+1, r = nums.size() - 1;
            while(l<r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum < 0)
                    l++;
                else if(sum > 0)
                    r--;
                else {
                    res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1])
                        l++;
                    while(l < r && nums[r] == nums[r-1])
                        r--;
                    l++; r--;
                }
            }
        }
        return res;
    }

int main()
{
    vector<int> arr = {-1,0,1,2,-1,-4};
    auto res = threeSumtoZero(arr);
    for(auto v : res) {
        for(auto num : v) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
