#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); i++) {
            if ((i>0) && (nums[i] == nums[i-1]))
                continue;
                
            for(int j = i+1; j<nums.size(); j++) {
                if ((j>i+1) && (nums[j] == nums[j-1]))
                    continue;
                    
                int l = j+1, r = nums.size() - 1;
                while(l<r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum < target)
                        l++;
                    else if(sum > target)
                        r--;
                    else {
                        res.push_back(vector<int> {nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l+1])
                            l++;
                        while(l < r && nums[r] == nums[r-1])
                            r--;
                        l++; r--;
                    }
                }
            }
        }
        return res;
    }

int main()
{
    vector<int> arr = {4, 1, 2, -1, 1, -3};
    auto res = fourSum(arr,1);
    for(auto v : res) {
        for(auto num : v) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
