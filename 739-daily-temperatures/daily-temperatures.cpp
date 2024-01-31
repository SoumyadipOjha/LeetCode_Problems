class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        //  vector<int> a(t.size(),0);
        //  stack<int> s;
        //  for(int i = 0; i < t.size(); i++){
        //      while(!s.empty() && t[i] >t[ s.top()]){
        //          int index = s.top();
        //          s.pop();
        //          a[index] = i - index;
        //      }
        //      s.push(i);
        //  }
        //  return a;
        int n = t.size();
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && t[i] >= t[s.top()]) {
                s.pop();
            };
            if (!s.empty())
                ans[i] = s.top() - i;

            s.push(i);
        }
        return ans;
    }
};
