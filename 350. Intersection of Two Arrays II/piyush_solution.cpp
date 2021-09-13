class Solution {
public:
    //time:O(m+n)  space:O(m+n)
    vector<int> m1_umap(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> res;
        unordered_map<int,int> mp1,mp2;
        for(auto x:nums1)
            mp1[x]++;
        
        for(auto x:nums2)
        {
            auto it = mp1.find(x);
            if(it!=mp1.end())
            {
                res.push_back(x);
                it->second--;
                if(it->second==0)   mp1.erase(x);
            }
        }
        return res;
    }
    //time:O(nlogn)  space:O(1)
    vector<int> m2_sort(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> res;

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
        return res;

    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        return m1_umap(nums1,nums2);
        //return m2_sort(nums1,nums2);

    }
};
