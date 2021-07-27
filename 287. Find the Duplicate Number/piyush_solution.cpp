class Solution {
public:
    int findDuplicate(vector<int>& a) {
        for(int i=0;i<a.size();i++)
        {
            if(a[abs(a[i])]<0)
                return abs(a[i]);
            else
                a[abs(a[i])]*=(-1);
        }
        return 0;
    }
};
