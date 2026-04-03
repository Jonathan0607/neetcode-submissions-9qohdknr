class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        // Optimization 1: Reference (const string&) avoids copying the input strings
        for(const string& s : strs) {
            res += to_string(s.size());
            res += '#';
            res += s; // Optimization 2: Append in place (avoid temp string creation)
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if(s.empty()) return ans;
        
        // REMOVED: ans.reserve() -> It causes massive overhead for single large strings.
        
        int i = 0;
        while(i < s.size()){
            int j = i;
            // 1. Find the delimiter
            while(s[j] != '#') {
                j++;
            }
            
            // 2. Parse length
            // s.substr here is tiny (just digits), so memory impact is negligible
            int length = stoi(s.substr(i, j - i));
            
            // 3. Move pointer to start of word
            i = j + 1;
            
            // 4. Extract word
            // Using substr + push_back moves the temporary string into the vector.
            // This is efficient enough for 99% of cases without manual loops.
            ans.push_back(s.substr(i, length));
            
            // 5. Move pointer to start of next number
            i += length;            
        }
        return ans;
    }
};