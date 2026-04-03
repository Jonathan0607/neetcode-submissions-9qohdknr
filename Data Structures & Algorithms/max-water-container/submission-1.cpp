class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l = 0;
        int r = heights.size()-1;

        while(l<r){
            int max = (r-l)*(std::min(heights[l], heights[r]));
            if(max>res){
                res = max;
            }
            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
            cout << max << "," << l << "," << r << "\n";
        }
        return res;
    }
};
