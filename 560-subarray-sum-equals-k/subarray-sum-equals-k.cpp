class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //   int ans=0;
          
        //   for(int i=0;i<nums.size();i++){
        //     int count=0;
        //      for(int j=i;j<nums.size();j++){
        //         count+=nums[j];
        //         if(count==k){
        //             cout<<count<<" ";
        //             // count=0;
        //             ans++;
        //         }
        //      }
        //   }
        //   return ans;
         unordered_map<int, int> mp;
        int prefix = 0;
        int count = 0;

        mp[0] = 1; 

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];

            if (mp.find(prefix - k) != mp.end()) {
                count += mp[prefix - k];
            }

            mp[prefix]++;
        }

        return count;
        
    }
};