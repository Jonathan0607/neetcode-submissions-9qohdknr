class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(int i = 0;i<strs.size();i++){
            encoded+=to_string(strs[i].length());
            encoded+="#";
            encoded+=strs[i];
        }
        // cout<<encoded;
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i<s.size()){
            string num = "";
            string word = "";
            while(true){
                num+=s[i];
                i++;
                if(s[i]=='#'){
                    i++;
                    break;
                }
            }
            int length = stoi(num);
            while(length>0){
                word+=s[i];
                length--;
                i++;
            }
            // cout<<word;
            result.push_back(word);
        }
        return result;
    }
};
