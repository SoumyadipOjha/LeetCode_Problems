class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
         vector<int> a(t.size(), 0); 
         stack<int> s;
         for(int i = 0; i < t.size(); i++){
             while(!s.empty() && t[i] > t[s.top()]){
                 int idx = s.top();
                 s.pop();
                 a[idx] = i - idx;
             }
             s.push(i);
         }
         return a;
    }
};
