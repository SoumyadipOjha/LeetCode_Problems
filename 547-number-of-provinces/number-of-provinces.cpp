class Solution {
private:
void dfs(int node,vector<vector<int>>&adjLs,vector<int>&vis){
    vis[node]=1;
    for(auto it:adjLs[node]){
        if(!vis[it]){
            dfs(it,adjLs,vis);
        }
    }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adjLs(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i !=j){
                    adjLs[i].push_back(j);
                }
            }
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adjLs,vis);
                count++;
            }
        }
        return count;
    }
};