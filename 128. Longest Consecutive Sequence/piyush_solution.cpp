class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(auto x:nums)
            mp[x]=false;
        
        int res=0 , cur=0;
        for(auto x:nums)
        {
            if(!mp[x])   //not visited yet
            {
                cur=1;
                mp[x]=true;
                int left=x-1;
                
                while(mp.find(left)!=mp.end() && !mp[left])
                {
                    mp[left]=true;
                    cur++ , left--;
                }
                
                int right=x+1;
                while(mp.find(right)!=mp.end() && !mp[right])
                {
                    mp[right]=true;
                    cur++ , right++ ;
                }
                
                res= max(res,cur);
            }
        }   
        return res;
    }
};
