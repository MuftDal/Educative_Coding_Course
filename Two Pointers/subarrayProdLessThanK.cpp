#include <bits/stdc++.h>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0, l = 0, prod = 1;
        for(int r = 0; r<nums.size(); r++) {
            prod *= nums[r];
            while(prod >= k && l <= r) {
                prod /= nums[l];
                l++;
            }
            if(prod < k)
                count += r - l + 1;
        }
        return count;
    }

int main()
{
    vector<int> arr = {10,5,2,6};
    cout<<numSubarrayProductLessThanK(arr, 100);

    return 0;
}
