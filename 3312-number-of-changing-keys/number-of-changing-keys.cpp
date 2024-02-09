class Solution {
public:
    int countKeyChanges(string s) {
        vector<char>a;
       for(auto x:s){ 
        
        a.push_back((char)tolower(x)); 
    } 
    int count=0;
    for(int i=0;i<a.size()-1;i++){
        if(a[i]!=a[i+1]){
            count++;
        }
    }
    return count;
    }
};