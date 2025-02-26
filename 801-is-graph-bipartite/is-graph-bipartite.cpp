class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>Col(n,-1);
        queue<int>q;

        for(int i=0;i<n;i++){
            if(Col[i]==-1){
                Col[i]=0;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int j=0;j<graph[node].size();j++){
                        // colour not assigned
                        if(Col[graph[node][j]]==-1){
                        Col[graph[node][j]]=(Col[node]+1)%2;
                        q.push(graph[node][j]); 
                        }
                        // colour assigned
                        if(Col[graph[node][j]]==Col[node])return 0;
                    }
                }
            }
        }
        return 1;
    }
};