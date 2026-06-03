class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0 ;
        // int temp1 = height[1] ;
        // int temp2 = height[0] ;
        // for(int i = 0 ; i < n ; i++)
        // {
        //     for(int j = i+1 ; j < n; j++)
        //     {
        //         int c = j-i;
        //         int b = min(height[i],height[j]);
        //         area = max(area,c*b);
        //     }
        // }
        // return area ;

        int left = 0 , right = n-1 ;
        while(left<right)
        {
            int width = right - left ;
            int c = min(height[left],height[right]) ;
            area = max(area,c*width);
            if(height[left]<height[right]) left++;
            else right--;
        } 
        return area ;
    }
};