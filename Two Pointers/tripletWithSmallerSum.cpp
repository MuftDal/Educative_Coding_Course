#include <bits/stdc++.h>

using namespace std;

int tripletWithSmallerSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i<nums.size()-2; i++) {
            int l = i+1, r = nums.size()-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum >= target)
                    r--;
                else {
                    count += r - l;
                    l++;
                }
            }
        }
        return count;
    }

int main()
{
    vector<int> arr = {-1, 4, 2, 1, 3};
    cout<<tripletWithSmallerSum(arr, 5);

    return 0;
}
