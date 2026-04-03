class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const string& s: strs){
            res += to_string(s.size());
            res += ',';
            res += s;        
        }
        return res;
    }

    vector<string> decode(string s) {

        vector<string> ans;
        if(s.size() == 0){
            return ans;
        }

        
        int n = 0;
        int i = 0;
        while(i< s.size()){
            int j = i;
            while (s[j] != ',') {
                j++;
            }
            
            int length = stoi(s.substr(i, j - i));
            
            i = j + 1;
            
            string word = s.substr(i, length);
            ans.push_back(word);
            
            i += length;            
        }
        return ans;
    }
};
