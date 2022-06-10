void DutchFlag(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        for(int i = 0; i<r;) {
            if(nums[i] == 0) {
                swap(nums[i], nums[l]);
                i++; l++;
            }
            else if(nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;
            }
            else
                i++;
        }
    }

int main()
{
    vector<int> arr = {1, 0, 2, 1, 0};
    DutchFlag(arr);
    for(auto num : arr)
        cout<<num<<" ";

    return 0;
}
