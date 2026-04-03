class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<pair<int, int>> count;
        vector<int> result;
        int n = 0;
        for(int i : nums){
            freq[i]++;
        }
        for(const auto& ans: freq){
            count.push_back({ans.second, ans.first});
        }
        sort(count.rbegin(), count.rend());
        for(int i = 0; i < k; i++){                
            result.push_back(count[i].second);
        }    
        return result;
    }
};
