class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        // FIX 1: Use 'const string&' to prevent copying the input data
        for(const string& s : strs) {
            res += to_string(s.size());
            res += '#';
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if(s.empty()) return ans;
        
        // Optimization: Reserve memory if you can guess the size
        // This prevents the vector from resizing/copying itself multiple times
        ans.reserve(s.size() / 5); 

        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#') j++;
            
            // This small substr is fine (SSO usually handles numbers)
            int length = stoi(s.substr(i, j - i));
            
            i = j + 1;
            
            // FIX 2: Direct push_back with substr is actually fine IF encode is fixed.
            // The massive 257MB came mostly from the Encode loop copy.
            ans.push_back(s.substr(i, length));
            
            i += length;            
        }
        return ans;
    }
};