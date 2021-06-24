class Solution {
public:
    vector<int> m1_sort(vector<int>& a, int k) {
        vector<int> t=a,t1;
        int i=0,j=t.size()-1,fi,fj; 
        //cout<<j;
        
        sort(t.begin(),t.end());
        
        while(i<j)
        {
            if((t[i]+t[j])==k)
                break;
            else if((t[i]+t[j])>k)
                j--;
            else
                i++;
        }
        
        for(fi=0;fi<a.size();fi++)
            if(a[fi]==t[i])
                break;
        
        for(fj=0;fj<a.size();fj++)
            if(a[fj]==t[j]  &&  fj!=fi)
                break;
        
        if(fi<fj)
        {
            t1.push_back(fi);
            t1.push_back(fj);
        }
        else
        {
            t1.push_back(fj);
            t1.push_back(fi);
        }
        
        return t1;
    }
    
    vector<int> m2_umap(vector<int>& a, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<a.size();i++)
            if(mp.find(k-a[i])!=mp.end())
                return {mp[k-a[i]],i};
            else
                mp[a[i]]=i;
        
        return {};
    }
    vector<int> twoSum(vector<int>& a, int k) {
        //return m1_sort(a,k);
        return m2_umap(a,k);
    }
};
