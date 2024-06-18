class Solution {
public:
    int minimumRecolors(string blocks, int k) {
       int minc=INT_MAX,cnt=0;
       for(int i=0;i<blocks.size();i++){
        if(blocks[i]=='W')cnt++;
        if(i<k-1)continue;
        minc=min(cnt,minc);
        if(blocks[i-(k-1)]=='W')cnt--;
       }
       return minc;
    }
};