class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(auto num:nums) count[num]++;
        priority_queue<pair<int,int>> heap_count;
        vector<int> answer;
        for(auto it=count.begin();it!=count.end();it++){
            heap_count.push(make_pair(it->second,it->first));
            if(heap_count.size()>count.size()-k){
                answer.push_back(heap_count.top().second);
                heap_count.pop();
            }
        }
        return answer;
    }
};
