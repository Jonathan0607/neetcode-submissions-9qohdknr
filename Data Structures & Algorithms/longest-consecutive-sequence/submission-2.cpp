class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;

        for(int n: nums){
            if(numSet.find(n-1) == numSet.end()){
                int length =0;
                while(numSet.find(n + length) != numSet.end()){
                    length++;
                }
                res = max(length, res);
            }
        }
        return res;
    }
};