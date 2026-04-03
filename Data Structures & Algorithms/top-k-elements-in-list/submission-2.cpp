class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> count(nums.size() + 1);        
        vector<int> result;
        for(int i : nums){
            freq[i]++;
        }
        for(const auto& ans: freq){
            count[ans.second].push_back(ans.first);
        }
        for(int i = count.size()-1; i > 0; i--){
            for(int n : count[i])                
                result.push_back(n);
            if(result.size() == k){
                return result;
            }
        }    
        return result;
    }
};
