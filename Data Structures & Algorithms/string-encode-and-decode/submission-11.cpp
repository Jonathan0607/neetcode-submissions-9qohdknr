class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        // 1. SYSTEM FIX: Use Reference (&) to avoid copying 50MB of data
        for(const string& s : strs) { 
            res += to_string(s.size());
            res += '#'; // Use '#' as it's standard for this problem (Solution 1 used it)
            res += s;        
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if(s.empty()) return ans;

        int i = 0;
        while(i < s.size()){
            int j = i;
            // Scan for delimiter
            while(s[j] != '#') {
                j++;
            }
            
            // 2. SYSTEM FIX: Avoid creating a string just to parse a number
            // (We still need a small string for stoi, but it's tiny)
            int length = stoi(s.substr(i, j - i));
            
            i = j + 1; // Skip delimiter
            
            // 3. SYSTEM FIX: Optimization
            // We use substr here because we need to store the word anyway.
            // But since we fixed the Encode loop, the total memory pressure is lower.
            ans.push_back(s.substr(i, length));
            
            i += length;            
        }
        return ans;
    }
};