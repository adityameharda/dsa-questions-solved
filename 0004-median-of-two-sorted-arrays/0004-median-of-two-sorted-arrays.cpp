class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>v;
        int i = 0 ;
        int j = 0 ;
        int end1 = nums1.size()-1;
        int end2 = nums2.size()-1;
        // if(end1 > end2)
        // {
        //     while(!end2)
        //     {
        //         if(nums[i] < nums[j])
        //             v.push_back(nums[i]);
        //         if(nums[i] > nums[j])
        //             v.push_back(nums[j]);
        //     }
        // }
        while(i<n && j < m)
        {
            if(nums1[i] >= nums2[j]){
                v.push_back(nums2[j]);
                j++;
            }
            else{
                v.push_back(nums1[i]);
                i++;
            }
        }
        while(i < n) 
        {
            v.push_back(nums1[i]);
            i++;
        }
        while(j < m) 
        {
            v.push_back(nums2[j]);
            j++;
        }
       
        int size = v.size();
        if(size%2 != 0) 
        {
             return v[size/2];
        }
        else
        {
           return (v[size/2] + v[(size/2) - 1])/2.0;
        }
    }
};