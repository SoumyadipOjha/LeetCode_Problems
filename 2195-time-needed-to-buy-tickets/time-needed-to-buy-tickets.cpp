class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count=0;
        int i=0;
        while(tickets[k]!=0){
            if(tickets[i]>0){
                count++;
                tickets[i]--;
                i=(i+1)%tickets.size();
            }
            else if(tickets[i]==0)i=(i+1)%tickets.size();
        }
        return count;
    }
};