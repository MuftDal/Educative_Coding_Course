#include <bits/stdc++.h>

using namespace std;

int windowSort(const vector<int> &nums) {
    int i = 0, j = nums.size()-1;
    while(i < nums.size() && nums[i] <= nums[i+1]) {
        i++;
    }
    if(i == nums.size()-1) {
        return 0;
    }
    
    while(j > 0 && nums[j] >= nums[j-1]) {
        j--;
    }
    
    int maxi= INT_MIN, mini = INT_MAX;
    for(int k = i; k<=j; k++) {
        maxi = max(maxi, nums[k]);
        mini = min(mini, nums[k]);
    }
    
    while(i > 0 && nums[i-1] > mini) {
        i--;
    }
    
    while(j < nums.size()-1 && nums[j+1] < maxi) {
        j++;
    }
    
    return j - i + 1;
}

int main()
{
    vector<int> arr = {1, 2, 5, 3, 7, 10, 9, 12};
    cout<<windowSort(arr);
    return 0;
}
