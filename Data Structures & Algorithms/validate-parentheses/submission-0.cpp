using namespace std;

class Solution {
public:
    bool isValid(string s) {
    stack<char> plates;
    unordered_map<char, char> closeOpen = {{')', '('},{'}', '{'}, {']', '['} };

    for(char a: s){
        if (closeOpen.count(a) > 0){
            if(plates.size() > 0 && plates.top() == closeOpen[a]){
                plates.pop();
            }
            else{
                return false;
            }
        }
        else{
            plates.push(a);
        }
    }

    if(plates.size()>0) return false;
    return true;

    }
};
