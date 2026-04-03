class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int a = 0;
        int l;
        int r;
        vector<vector<int>> res;

        while(a < nums.size()-2){
            l = a+1;
            r = nums.size()-1;
            while(l < r){
                int sum = nums[a] + nums[l] + nums[r];
                if(sum == 0){
                    res.push_back({nums[a], nums[l], nums[r]});
                    l++;
                    while(l<r && nums[l] == nums[l-1]) l++;
                }
                else if(sum > 0){
                    r--;
                }
                else if(sum < 0){
                    l++;
                }
            }
            a++;
            while(a < (int)nums.size()-2 && nums[a] == nums[a-1]) a++;
        };
        return res;
    }
};
