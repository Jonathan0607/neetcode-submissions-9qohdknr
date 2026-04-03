class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string s: strs){
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

        string word;
        int n = 0;

        for(int i = 0; i < s.size(); i++){
            if(n>0){
                word += s[i];
                n--;
            }
            else{
                string count = "";
                if(i!=0){
                ans.push_back(word);
                word = "";
                }

                while(s[i] != ','){
                    count += s[i];
                    i++;
                }
                n = stoi(count);
            }
        }
        ans.push_back(word);
        return ans;
    }
};
