class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0&&nums[i]==nums[i-1]) continue;
            int low(i+1),high(nums.size()-1);
            int sum=-nums[i];
            while(low<high){
                int tmpsum=nums[low]+nums[high];
                if(tmpsum==sum){
                    res.push_back({nums[i],nums[low],nums[high]});
                    while(nums[++low]==nums[low-1]);
                    while(nums[--high]==nums[high+1]);
                }
                else if(tmpsum<sum) low++;
                else high--;
            }
        }
        return res;
    }
};