class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        pair<int,int>p1 = {rec1[0],rec1[1]};
        pair<int,int>p2 = {rec1[2],rec1[3]};
        pair<int,int>p3 = {rec2[0],rec2[1]};
        pair<int,int>p4 = {rec2[2],rec2[3]};
        
        int left  = max(p1.first, p3.first);
        int right = min(p2.first, p4.first);
        int x_range = right - left ;

        int bottom = max(p1.second, p3.second);
        int top = min(p2.second, p4.second);
        int y_range = top - bottom;

         return x_range > 0 && y_range > 0;
    }
};