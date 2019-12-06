class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums;
        int len1 = int(nums1.size());
        int len2 = int(nums2.size());
        if(len1==0 && len2 == 0)
        {
            return 0;
        }
        else
        {
            for(int i = 0 ; i < len1 ; i++)
            {
                nums.push_back(nums1[i]);
            }
            for(int i = 0 ; i < len2 ; i++)
            {
                nums.push_back(nums2[i]);
            }
            sort(nums.begin() , nums.end());
            int len = nums.size();
            double x;
            if(len%2==0)
            {
                x = (nums[len/2] + nums[len/2-1])/2.0;
            }
            else
            {
                x = nums[len/2];
            }
            return x;
        }
      
    }
};