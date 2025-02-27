class Solution {
public:
int r,c;
int row[4]={-1,+1,0,0};
int col[4]={0,0,-1,+1};
bool isValid(int i,int j){
    return (i>=0 && i<r && j>=0 && j<c);
}
    void solve(vector<vector<char>>& board) {
        r=board.size();
        c=board[0].size();
        // apply BFS in borderline and convert 0 to T
        queue<pair<int,int>>q;
        // first row
        for(int i=0;i<c;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                board[0][i]='T';
            }
        }
        // first col
        for(int i=1;i<r;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                board[i][0]='T';
            }
        }

        // last row
        for(int i=1;i<c;i++){
            if(board[r-1][i]=='O'){
                q.push({r-1,i});
                board[r-1][i]='T';
            }
        }
        // last col
        for(int i=1;i<r-1;i++){
            if(board[i][c-1]=='O'){
                q.push({i,c-1});
                board[i][c-1]='T';
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                if(isValid(i+row[k],j+col[k]) && board[i+row[k]][j+col[k]]=='O'){
                    board[i+row[k]][j+col[k]]='T';
                    q.push({i+row[k],j+col[k]});   
                }
            }
        }
        // replace all T to 0 and all 0 with X
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            if(board[i][j]=='O')board[i][j]='X';
            if(board[i][j]=='T')board[i][j]='O';
        }
    }
};