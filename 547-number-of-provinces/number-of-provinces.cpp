class Solution {
public:
void DFS(int node,vector<vector<int>>& isConnected,vector<int>&vis){
    vis[node]=1;
    // check for neighbours
    for(int j=0;j<isConnected[node].size();j++){
        if (isConnected[node][j] == 1 && !vis[j]){
            DFS(j,isConnected,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int counter=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                counter++;
                DFS(i,isConnected,vis);
            }
        }
        return counter;
    }
};