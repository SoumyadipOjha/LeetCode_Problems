class Solution {
public:
    vector<int> twoSum(vector<int>& s, int target) {
     int left=0;
     int right=s.size()-1;
     while(left<right){
        int sum =s[left]+s[right];
        if(sum==target)return {left+1,right+1};
        else if(sum>target)right--;
        else{left++;}
     }
     return {-1,-1};

    }
};
