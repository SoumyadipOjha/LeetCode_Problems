class Solution {
public:
void DFS(int node,vector<vector<int>>& adjLs,vector<int>&vis){
    vis[node]=1;
    // check for neighbours
    for(int j=0;j<adjLs[node].size();j++){
        if(!vis[adjLs[node][j]]){
            DFS(adjLs[node][j],adjLs,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adjLs(n);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(isConnected[i][j]==1 && i!=j)adjLs[i].push_back(j);
        
        vector<int>vis(n,0);
        int counter=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                counter++;
                DFS(i,adjLs,vis);
            }
        }
        return counter;
    }
};