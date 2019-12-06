//暴力法
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i , x , y;
        for(i = 0 ; i < nums.size(); i++)
        {
           x = nums.count(target-nums[i]);
           return{i,x};
        }
    }
};
*/
//哈希法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        vector<int>Answer;
        int len = int(nums.size());
        for(int i = 0 ; i < len ; i++)
        {
            int findAnswer  = target - nums[i];
            if(hash.find(findAnswer) != hash.end())
            {
                Answer.push_back(hash[findAnswer]);
                Answer.push_back(i);
                return Answer;
            }
            hash[nums[i]] = i;
        }
        return Answer;
    }
};