class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1);
        queue<int>q;

        // Step 1: check kro agar koi v colour nahi h to 0 colour kro and q m dalo
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                col[i]=0;
                q.push(i);
                while(!q.empty()){
                    // q se nikalo and check kro 
                    int node=q.front();
                    q.pop();
                     // check for neighbours
                    for(int j=0;j<graph[node].size();j++){
                        // ya to neighbour not coloured hoga
                        if(col[graph[node][j]]==-1){
                            col[graph[node][j]]=(col[node]+1)%2;
                            q.push(graph[node][j]);
                        }
                        // ya to already coloured hoga 
                        if(col[graph[node][j]]==col[node])return 0; 
                    }
                }
            }
        }
        return 1;
    }
};