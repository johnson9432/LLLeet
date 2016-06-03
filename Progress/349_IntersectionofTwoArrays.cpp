class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> stats(nums1.begin(),nums1.end());
        vector<int> res;
        for(int i:nums2){
            if(stats.find(i)!=stats.end()) {res.push_back(i);stats.erase(i);}
        }
        return res;
    }
};