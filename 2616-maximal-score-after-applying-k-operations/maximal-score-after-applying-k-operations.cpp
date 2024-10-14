class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq;
        for(auto &it:nums)pq.push(it);
        long long score=0;
        long double temp;
        while(k--){
            temp=pq.top();
            score+=temp;
            pq.pop();
            pq.push(ceil(temp/3));
        }
        return score;
    }
};