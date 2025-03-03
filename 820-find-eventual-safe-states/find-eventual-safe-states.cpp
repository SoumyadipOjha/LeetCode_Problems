class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>revAdj(n);
        vector<int>inDeg(n,0);
        for(int i=0;i<n;i++){
            for(const auto &a:graph[i]){
                revAdj[a].push_back(i);
                inDeg[i]++;
            }
        }

        

        queue<int>q;
        vector<int>safeStates;

        for(int i=0;i<n;i++){
            if(!inDeg[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safeStates.push_back(node);
            for(int j=0;j<revAdj[node].size();j++){
                inDeg[revAdj[node][j]]--;
                if(!inDeg[revAdj[node][j]])q.push(revAdj[node][j]);
            }
        }

        sort(safeStates.begin(),safeStates.end());
        return safeStates;

        
    }
};