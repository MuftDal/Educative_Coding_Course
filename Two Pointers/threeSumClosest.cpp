#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int smallestDiff = INT_MAX;
        for(int i = 0; i<nums.size()-2; i++) {
            int l = i+1, r = nums.size()-1;
            while(l < r) {
                int targetDiff = target - nums[i] - nums[l] - nums[r];
                if(targetDiff == 0) {
                    return target - targetDiff;
                }
                    
                if(abs(targetDiff) < abs(smallestDiff)) {
                    smallestDiff = targetDiff;
                }
                
                if(targetDiff > 0)
                    l++;
                else
                    r--;
            }
        }
        return target - smallestDiff;
    }

int main()
{
    vector<int> arr = {-1,0,1,2,-1,-4};
    cout<<threeSumClosest(arr, 5);

    return 0;
}
