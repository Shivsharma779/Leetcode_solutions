class Solution {
public:
    void combination(vector<int>& a, int &target, int csum, int i,
                vector<vector<int>> &res, vector<int> &tempv)
    {
        if(csum==target)
            res.push_back(tempv);
        else if(csum<target)
        {                           //stop loop when adding current value 
                                    //surpasses target, we will stop at that point
                                    //to avoid extra recursive calls
            for(int j=i;j<a.size() && (target-csum)>=a[j];j++)
            {
                tempv.push_back(a[j]);
                combination(a,target,csum+a[j],j,res,tempv);
                tempv.pop_back();
            }
        }
    }
        
        
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        sort(a.begin(),a.end());        //to avoid extra recursive calls
                                        //for larger numbers
        vector<vector<int>> res;
        vector<int> tempv;          //store numbers in current recursive call
        combination(a,target,0,0,res,tempv);  //arr,target,sum,idx,res_vector,current_stack
        return res;
    }
};
