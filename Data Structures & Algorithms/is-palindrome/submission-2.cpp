class Solution {
public:
    bool isPalindrome(string s) {
        int x = 0;
        int y = s.size()-1;
        while(x < y){
            while(!isalnum(s[x])){
                x++;
            }
            while(!isalnum(s[y])){
                y--;
            }
            if(x >= y){
                break;
            }
            if(tolower(s[x]) != tolower(s[y])){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
};
